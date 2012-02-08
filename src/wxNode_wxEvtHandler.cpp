
#include "wxNode_wxEvtHandler.h"
#include "wxNode_wxEvent.h"
#include "wxNode_wxKeyEvent.h"
#include "wxNodeObject.h"

ListenerData::ListenerData(int eventType, v8::Local<v8::Object> fn, fnNewEvent* NewEvent) {
  m_eventType = eventType;
  m_fn = v8::Persistent<v8::Object>::New(fn); // TODO: cleanup persistent
  this->NewEvent = NewEvent;
}

/*static*/ void wxNode_wxEvtHandler::AddMethods(v8::Handle<v8::FunctionTemplate> func) {
  wxNodeObject::AddMethods(func);
  NODE_SET_PROTOTYPE_METHOD(func, "EVT_MENU", _EVT_MENU);
  NODE_SET_PROTOTYPE_METHOD(func, "EVT_IDLE", _EVT_IDLE);
  NODE_SET_PROTOTYPE_METHOD(func, "EVT_CLOSE", _EVT_CLOSE);
  NODE_SET_PROTOTYPE_METHOD(func, "EVT_KEY_DOWN", _EVT_KEY_DOWN);
  NODE_SET_PROTOTYPE_METHOD(func, "connect", _connect);
}

v8::Handle<v8::Value> NewEvent_wxEvent(wxEvent& event) {
  return wxNode_wxEvent::NewCopy(event);
}

v8::Handle<v8::Value> NewEvent_wxKeyEvent(wxEvent& event) {
  return wxNode_wxKeyEvent::NewCopy(*((wxKeyEvent*)&event));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxEvtHandler::_connect(const v8::Arguments& args) {
  wxEvtHandler* evtHandler = unwrap<wxEvtHandler>(args.This());
  NodeExEvtHandlerImpl* self = unwrapEvtHandler(args.This());

  v8::Local<v8::Int32> idObj = args[0]->ToInt32();
  int32_t eventType = idObj->Value();

  if(!args[1]->IsFunction()) {
    printf("Invalid Arg\n"); // TODO: throw exception
  }
  v8::Local<v8::Object> fnObj = args[1]->ToObject();

  self->connect(evtHandler, eventType, fnObj, NewEvent_wxEvent);

  return v8::Undefined();
}

/*static*/ v8::Handle<v8::Value> wxNode_wxEvtHandler::_EVT_MENU(const v8::Arguments& args) {
  wxEvtHandler* evtHandler = unwrap<wxEvtHandler>(args.This());
  NodeExEvtHandlerImpl* self = unwrapEvtHandler(args.This());

  v8::Local<v8::Int32> idObj = args[0]->ToInt32();
  int32_t id = idObj->Value();

  if(!args[1]->IsFunction()) {
    printf("Invalid Arg\n"); // TODO: throw exception
  }
  v8::Local<v8::Object> fnObj = args[1]->ToObject();

  self->addCommandListener(evtHandler, id, wxEVT_COMMAND_MENU_SELECTED, fnObj, NewEvent_wxEvent);

  return v8::Undefined();
}

/*static*/ v8::Handle<v8::Value> wxNode_wxEvtHandler::_EVT_KEY_DOWN(const v8::Arguments& args) {
  wxEvtHandler* evtHandler = unwrap<wxEvtHandler>(args.This());
  NodeExEvtHandlerImpl* self = unwrapEvtHandler(args.This());

  if(!args[0]->IsFunction()) {
    printf("Invalid Arg\n"); // TODO: throw exception
  }
  v8::Local<v8::Object> fnObj = args[0]->ToObject();

  self->connect(evtHandler, wxEVT_KEY_DOWN, fnObj, NewEvent_wxKeyEvent);

  return v8::Undefined();
}

/*static*/ v8::Handle<v8::Value> wxNode_wxEvtHandler::_EVT_IDLE(const v8::Arguments& args) {
  wxNode_wxEvtHandler* evtHandler = unwrap<wxNode_wxEvtHandler>(args.This());
  NodeExEvtHandlerImpl* self = unwrapEvtHandler(args.This());

  if(!args[0]->IsFunction()) {
    printf("Invalid Arg\n"); // TODO: throw exception
  }
  v8::Local<v8::Object> fnObj = args[0]->ToObject();

  self->addEventListener(evtHandler, wxEVT_IDLE, fnObj, NewEvent_wxEvent);

  return v8::Undefined();
}

/*static*/ v8::Handle<v8::Value> wxNode_wxEvtHandler::_EVT_CLOSE(const v8::Arguments& args) {
  wxNode_wxEvtHandler* evtHandler = unwrap<wxNode_wxEvtHandler>(args.This());
  NodeExEvtHandlerImpl* self = unwrapEvtHandler(args.This());

  if(!args[0]->IsFunction()) {
    printf("Invalid Arg\n"); // TODO: throw exception
  }
  v8::Local<v8::Object> fnObj = args[0]->ToObject();

  self->addEventListener(evtHandler, wxEVT_CLOSE_WINDOW, fnObj, NewEvent_wxEvent);

  return v8::Undefined();
}

NodeExEvtHandlerImpl::NodeExEvtHandlerImpl() {
  m_listeners = new std::vector<ListenerData*>();
}

NodeExEvtHandlerImpl::~NodeExEvtHandlerImpl() {
  printf("delete NodeExEvtHandlerImpl\n");
  delete m_listeners;
}

void NodeExEvtHandlerImpl::fireEvent(uint32_t iListener, wxEvent& event) {
  if(iListener < 0 || iListener > m_listeners->size()) { return; }
  ListenerData* listenerData = (*m_listeners)[iListener];
  if(!listenerData) { return; }
  v8::Function* fn = v8::Function::Cast(*listenerData->m_fn);

  v8::TryCatch tryCatch;
  v8::Handle<v8::Value> argv[1];
  argv[0] = listenerData->NewEvent(event);
  fn->Call(this->self(), 1, argv);
  if(tryCatch.HasCaught()) {
    v8::String::AsciiValue ex(tryCatch.Exception());
    printf("fireEvent: %s\n", *ex); // TODO: handle this better
  }
}

void EventProxy::forwardEvent(wxEvent& event) {
  EventProxyData* data = (EventProxyData*)event.m_callbackUserData;
  if(data) {
    data->m_self->fireEvent(data->m_iListener, event);
  }
}

void NodeExEvtHandlerImpl::connect(wxEvtHandler* evtHandler, int id, int lastId, int eventType, v8::Local<v8::Object> fn, fnNewEvent* NewEvent) {
  // TODO: memory cleanup
  m_listeners->push_back(new ListenerData(eventType, fn, NewEvent));
  int iListener = m_listeners->size() - 1;

  EventProxyData* data = new EventProxyData();
  data->m_self = this;
  data->m_iListener = iListener;

  evtHandler->Connect(id, lastId, eventType, (wxObjectEventFunction)&EventProxy::forwardEvent, data);
}

void NodeExEvtHandlerImpl::connect(wxEvtHandler* evtHandler, int eventType, v8::Local<v8::Object> fn, fnNewEvent* NewEvent) {
  // TODO: memory cleanup
  m_listeners->push_back(new ListenerData(eventType, fn, NewEvent));
  int iListener = m_listeners->size() - 1;

  EventProxyData* data = new EventProxyData();
  data->m_self = this;
  data->m_iListener = iListener;

  evtHandler->Connect(eventType, (wxObjectEventFunction)&EventProxy::forwardEvent, data);
}

void NodeExEvtHandlerImpl::addEventListener(wxEvtHandler* evtHandler, int eventType, v8::Local<v8::Object> fn, fnNewEvent* NewEvent) {
  addCommandRangeListener(evtHandler, -1, -1, eventType, fn, NewEvent);
}

void NodeExEvtHandlerImpl::addCommandRangeListener(wxEvtHandler* evtHandler, int id, int lastId, int eventType, v8::Local<v8::Object> fn, fnNewEvent* NewEvent) {
  connect(evtHandler, id, lastId, eventType, fn, NewEvent);
}

void NodeExEvtHandlerImpl::addCommandListener(wxEvtHandler* evtHandler, int id, int eventType, v8::Local<v8::Object> fn, fnNewEvent* NewEvent) {
  addCommandRangeListener(evtHandler, id, -1, eventType, fn, NewEvent);
}
