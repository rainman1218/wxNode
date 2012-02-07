
#include <sstream>
#include "wxNode_wxPoint.h"
#include "wxNode_wxRealPoint.h"


/* static */ v8::Persistent<v8::FunctionTemplate> wxNode_wxPoint::s_ct;



wxNode_wxPoint::wxNode_wxPoint(wxNode_wxPoint& arg0)
  : wxPoint(arg0)
{

}

wxNode_wxPoint::wxNode_wxPoint()
  : wxPoint()
{

}

wxNode_wxPoint::wxNode_wxPoint(int xx, int yy)
  : wxPoint(xx, yy)
{

}

wxNode_wxPoint::wxNode_wxPoint(wxNode_wxRealPoint& pt)
  : wxPoint(pt)
{

}




/*static*/ void wxNode_wxPoint::Init(v8::Handle<v8::Object> target) {
  v8::HandleScope scope;

  v8::Local<v8::FunctionTemplate> t = v8::FunctionTemplate::New(wxNodeObject::NewFunc);
  s_ct = v8::Persistent<v8::FunctionTemplate>::New(t);
  s_ct->InstanceTemplate()->SetInternalFieldCount(2);
  s_ct->SetClassName(v8::String::NewSymbol("wxPoint"));

  NODE_SET_PROTOTYPE_METHOD(s_ct, "init", _init);
  AddMethods(s_ct);

  target->Set(v8::String::NewSymbol("wxPoint"), s_ct->GetFunction());
}

/*static*/ void wxNode_wxPoint::AddMethods(v8::Handle<v8::FunctionTemplate> target) {
  wxNode_wxEvtHandler::AddMethods(target);
  NODE_SET_PROTOTYPE_METHOD(target, "isFullySpecified", _IsFullySpecified);
  NODE_SET_PROTOTYPE_METHOD(target, "setDefaults", _SetDefaults);
  
}

/*static*/ v8::Handle<v8::Value> wxNode_wxPoint::_init(const v8::Arguments& args) {
  v8::HandleScope scope;

  
  
  /*
   * id: _26544
   */
  if(args.Length() == 1 && (args[0]->IsNull() || args[0]->IsObject())) {
    wxNode_wxPoint* arg0 = args[0]->IsNull() ? NULL : wxNodeObject::unwrap<wxNode_wxPoint>(args[0]->ToObject()); /* type: _20412  */
    

    wxNode_wxPoint *self = new wxNode_wxPoint(*arg0);
    NodeExEvtHandlerImpl* evtHandler = dynamic_cast<NodeExEvtHandlerImpl*>(self);
    self->wrap(args.This(), self, evtHandler);
    return args.This();
  }
  
  /*
   * id: _26545
   */
  if(args.Length() == 0) {
    

    wxNode_wxPoint *self = new wxNode_wxPoint();
    NodeExEvtHandlerImpl* evtHandler = dynamic_cast<NodeExEvtHandlerImpl*>(self);
    self->wrap(args.This(), self, evtHandler);
    return args.This();
  }
  
  /*
   * id: _26546
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsNumber()) {
    int xx = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    int yy = (int)args[1]->ToInt32()->Value(); /* type: _162  */
    

    wxNode_wxPoint *self = new wxNode_wxPoint(xx, yy);
    NodeExEvtHandlerImpl* evtHandler = dynamic_cast<NodeExEvtHandlerImpl*>(self);
    self->wrap(args.This(), self, evtHandler);
    return args.This();
  }
  
  /*
   * id: _26547
   */
  if(args.Length() == 1 && (args[0]->IsNull() || args[0]->IsObject())) {
    wxNode_wxRealPoint* pt = args[0]->IsNull() ? NULL : wxNodeObject::unwrap<wxNode_wxRealPoint>(args[0]->ToObject()); /* type: _20523  */
    

    wxNode_wxPoint *self = new wxNode_wxPoint(*pt);
    NodeExEvtHandlerImpl* evtHandler = dynamic_cast<NodeExEvtHandlerImpl*>(self);
    self->wrap(args.This(), self, evtHandler);
    return args.This();
  }
  
  

  std::ostringstream errStr;
  errStr << "Could not find matching constructor for arguments (class name: wxPoint).\n";                           \
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}


/*static*/ v8::Handle<v8::Value> wxNode_wxPoint::_IsFullySpecified(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxPoint* self = unwrap<wxNode_wxPoint>(args.This());

  
  /*
   * id: _26552
   */
  if(args.Length() == 0) {
    

    self->IsFullySpecified();

    return v8::Undefined();
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: IsFullySpecified).\n";                           \
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxPoint::_SetDefaults(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxPoint* self = unwrap<wxNode_wxPoint>(args.This());

  
  /*
   * id: _26553
   */
  if(args.Length() == 1 && (args[0]->IsNull() || args[0]->IsObject())) {
    wxNode_wxPoint* pt = args[0]->IsNull() ? NULL : wxNodeObject::unwrap<wxNode_wxPoint>(args[0]->ToObject()); /* type: _20412  */
    

    self->SetDefaults(*pt);

    return v8::Undefined();
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: SetDefaults).\n";                           \
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}
