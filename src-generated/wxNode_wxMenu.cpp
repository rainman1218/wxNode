
#include "wxNode_wxMenu.h"
#include "wxNode_wxEvtHandler.h"
#include "wxNode_wxItemKind.h"
#include "wxNode_wxMenuItem.h"
#include "wxNode_wxWindow.h"
#include "wxNode_wxMenuBar.h"


/* static */ v8::Persistent<v8::FunctionTemplate> wxNode_wxMenu::s_ct;



wxNode_wxMenu::wxNode_wxMenu(const wxString& title, long int style)
  : wxMenu(title, style)
{

}

wxNode_wxMenu::wxNode_wxMenu(const wxString& title)
  : wxMenu(title)
{

}

wxNode_wxMenu::wxNode_wxMenu(long int style)
  : wxMenu(style)
{

}

wxNode_wxMenu::wxNode_wxMenu()
  : wxMenu()
{

}




/*static*/ void wxNode_wxMenu::Init(v8::Handle<v8::Object> target) {
  v8::HandleScope scope;

  v8::Local<v8::FunctionTemplate> t = v8::FunctionTemplate::New(wxNodeObject::NewFunc);
  s_ct = v8::Persistent<v8::FunctionTemplate>::New(t);
  s_ct->InstanceTemplate()->SetInternalFieldCount(2);
  s_ct->SetClassName(v8::String::NewSymbol("wxMenu"));

  NODE_SET_PROTOTYPE_METHOD(s_ct, "init", _init);
  AddMethods(s_ct);

  target->Set(v8::String::NewSymbol("wxMenu"), s_ct->GetFunction());
}

/*static*/ void wxNode_wxMenu::AddMethods(v8::Handle<v8::FunctionTemplate> target) {
  wxNode_wxEvtHandler::AddMethods(target);
  NODE_SET_PROTOTYPE_METHOD(target, "new", _New);
  NODE_SET_PROTOTYPE_METHOD(target, "append", _Append);
  NODE_SET_PROTOTYPE_METHOD(target, "appendSeparator", _AppendSeparator);
  NODE_SET_PROTOTYPE_METHOD(target, "appendCheckItem", _AppendCheckItem);
  NODE_SET_PROTOTYPE_METHOD(target, "appendRadioItem", _AppendRadioItem);
  NODE_SET_PROTOTYPE_METHOD(target, "appendSubMenu", _AppendSubMenu);
  NODE_SET_PROTOTYPE_METHOD(target, "break", _Break);
  NODE_SET_PROTOTYPE_METHOD(target, "insert", _Insert);
  NODE_SET_PROTOTYPE_METHOD(target, "insertSeparator", _InsertSeparator);
  NODE_SET_PROTOTYPE_METHOD(target, "insertCheckItem", _InsertCheckItem);
  NODE_SET_PROTOTYPE_METHOD(target, "insertRadioItem", _InsertRadioItem);
  NODE_SET_PROTOTYPE_METHOD(target, "prepend", _Prepend);
  NODE_SET_PROTOTYPE_METHOD(target, "prependSeparator", _PrependSeparator);
  NODE_SET_PROTOTYPE_METHOD(target, "prependCheckItem", _PrependCheckItem);
  NODE_SET_PROTOTYPE_METHOD(target, "prependRadioItem", _PrependRadioItem);
  NODE_SET_PROTOTYPE_METHOD(target, "remove", _Remove);
  NODE_SET_PROTOTYPE_METHOD(target, "delete", _Delete);
  NODE_SET_PROTOTYPE_METHOD(target, "destroy", _Destroy);
  NODE_SET_PROTOTYPE_METHOD(target, "getMenuItemCount", _GetMenuItemCount);
  NODE_SET_PROTOTYPE_METHOD(target, "getMenuItems", _GetMenuItems);
  NODE_SET_PROTOTYPE_METHOD(target, "findItem", _FindItem);
  NODE_SET_PROTOTYPE_METHOD(target, "findItemByPosition", _FindItemByPosition);
  NODE_SET_PROTOTYPE_METHOD(target, "enable", _Enable);
  NODE_SET_PROTOTYPE_METHOD(target, "isEnabled", _IsEnabled);
  NODE_SET_PROTOTYPE_METHOD(target, "check", _Check);
  NODE_SET_PROTOTYPE_METHOD(target, "isChecked", _IsChecked);
  NODE_SET_PROTOTYPE_METHOD(target, "setLabel", _SetLabel);
  NODE_SET_PROTOTYPE_METHOD(target, "getLabel", _GetLabel);
  NODE_SET_PROTOTYPE_METHOD(target, "getLabelText", _GetLabelText);
  NODE_SET_PROTOTYPE_METHOD(target, "setHelpString", _SetHelpString);
  NODE_SET_PROTOTYPE_METHOD(target, "getHelpString", _GetHelpString);
  NODE_SET_PROTOTYPE_METHOD(target, "setTitle", _SetTitle);
  NODE_SET_PROTOTYPE_METHOD(target, "getTitle", _GetTitle);
  NODE_SET_PROTOTYPE_METHOD(target, "setEventHandler", _SetEventHandler);
  NODE_SET_PROTOTYPE_METHOD(target, "getEventHandler", _GetEventHandler);
  NODE_SET_PROTOTYPE_METHOD(target, "setInvokingWindow", _SetInvokingWindow);
  NODE_SET_PROTOTYPE_METHOD(target, "getInvokingWindow", _GetInvokingWindow);
  NODE_SET_PROTOTYPE_METHOD(target, "getWindow", _GetWindow);
  NODE_SET_PROTOTYPE_METHOD(target, "getStyle", _GetStyle);
  NODE_SET_PROTOTYPE_METHOD(target, "updateUI", _UpdateUI);
  NODE_SET_PROTOTYPE_METHOD(target, "getMenuBar", _GetMenuBar);
  NODE_SET_PROTOTYPE_METHOD(target, "attach", _Attach);
  NODE_SET_PROTOTYPE_METHOD(target, "detach", _Detach);
  NODE_SET_PROTOTYPE_METHOD(target, "isAttached", _IsAttached);
  NODE_SET_PROTOTYPE_METHOD(target, "setParent", _SetParent);
  NODE_SET_PROTOTYPE_METHOD(target, "getParent", _GetParent);
  NODE_SET_PROTOTYPE_METHOD(target, "findChildItem", _FindChildItem);
  NODE_SET_PROTOTYPE_METHOD(target, "sendEvent", _SendEvent);
  NODE_SET_PROTOTYPE_METHOD(target, "lockAccels", _LockAccels);
  
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_init(const v8::Arguments& args) {
  v8::HandleScope scope;

  
  
  /*
   * id: _17680
   */
  if(args.Length() == 2 && args[0]->IsString() && args[1]->IsNumber()) {
    v8::String::AsciiValue title(args[0]->ToString()); /* type: _14808  */
    long int style = (long int)args[1]->ToInt32()->Value(); /* type: _586  */
    

    wxNode_wxMenu *self = new wxNode_wxMenu(*title, style);
    NodeExEvtHandlerImpl* evtHandler = dynamic_cast<NodeExEvtHandlerImpl*>(self);
    self->wrap(args.This(), self, evtHandler);
    return args.This();
  }
  
  /*
   * id: _17680
   */
  if(args.Length() == 1 && args[0]->IsString()) {
    v8::String::AsciiValue title(args[0]->ToString()); /* type: _14808  */
    

    wxNode_wxMenu *self = new wxNode_wxMenu(*title);
    NodeExEvtHandlerImpl* evtHandler = dynamic_cast<NodeExEvtHandlerImpl*>(self);
    self->wrap(args.This(), self, evtHandler);
    return args.This();
  }
  
  /*
   * id: _17681
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    long int style = (long int)args[0]->ToInt32()->Value(); /* type: _586  */
    

    wxNode_wxMenu *self = new wxNode_wxMenu(style);
    NodeExEvtHandlerImpl* evtHandler = dynamic_cast<NodeExEvtHandlerImpl*>(self);
    self->wrap(args.This(), self, evtHandler);
    return args.This();
  }
  
  /*
   * id: _17681
   */
  if(args.Length() == 0) {
    

    wxNode_wxMenu *self = new wxNode_wxMenu();
    NodeExEvtHandlerImpl* evtHandler = dynamic_cast<NodeExEvtHandlerImpl*>(self);
    self->wrap(args.This(), self, evtHandler);
    return args.This();
  }
  
  

  return v8::ThrowException(v8::String::New("Could not find matching constructor for arguments (class name: wxMenu)."));
}


/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_New(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44711
   */
  if(args.Length() == 2 && args[0]->IsString() && args[1]->IsNumber()) {
    v8::String::AsciiValue title(args[0]->ToString()); /* type: _14808  */
    long int style = (long int)args[1]->ToInt32()->Value(); /* type: _586  */
    

    self->New(*title, style);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44711
   */
  if(args.Length() == 1 && args[0]->IsString()) {
    v8::String::AsciiValue title(args[0]->ToString()); /* type: _14808  */
    

    self->New(*title);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44711
   */
  if(args.Length() == 0) {
    

    self->New();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: New)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_Append(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44715
   */
  if(args.Length() == 4 && args[0]->IsNumber() && args[1]->IsString() && args[2]->IsString() && args[3]->IsObject()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[2]->ToString()); /* type: _14808  */
    wxNode_wxItemKind* kind = wxNodeObject::unwrap<wxNode_wxItemKind>(args[3]->ToObject()); /* type: _4625  */
    

    self->Append(itemid, *text, *help, kind);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44715
   */
  if(args.Length() == 3 && args[0]->IsNumber() && args[1]->IsString() && args[2]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[2]->ToString()); /* type: _14808  */
    

    self->Append(itemid, *text, *help);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44715
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    

    self->Append(itemid, *text);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44715
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    

    self->Append(itemid);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44720
   */
  if(args.Length() == 1 && args[0]->IsObject()) {
    wxNode_wxMenuItem* item = wxNodeObject::unwrap<wxNode_wxMenuItem>(args[0]->ToObject()); /* type: _51683 * */
    

    self->Append(item);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44772
   */
  if(args.Length() == 4 && args[0]->IsNumber() && args[1]->IsString() && args[2]->IsString() && args[3]->IsBoolean()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[2]->ToString()); /* type: _14808  */
    bool isCheckable = args[3]->ToBoolean()->Value(); /* type: _14666  */
    

    self->Append(itemid, *text, *help, isCheckable);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44773
   */
  if(args.Length() == 4 && args[0]->IsNumber() && args[1]->IsString() && args[2]->IsObject() && args[3]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    wxNode_wxMenu* submenu = wxNodeObject::unwrap<wxNode_wxMenu>(args[2]->ToObject()); /* type: _52838 * */
    v8::String::AsciiValue help(args[3]->ToString()); /* type: _14808  */
    

    self->Append(itemid, *text, submenu, *help);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44773
   */
  if(args.Length() == 3 && args[0]->IsNumber() && args[1]->IsString() && args[2]->IsObject()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    wxNode_wxMenu* submenu = wxNodeObject::unwrap<wxNode_wxMenu>(args[2]->ToObject()); /* type: _52838 * */
    

    self->Append(itemid, *text, submenu);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: Append)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_AppendSeparator(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44716
   */
  if(args.Length() == 0) {
    

    self->AppendSeparator();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: AppendSeparator)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_AppendCheckItem(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44717
   */
  if(args.Length() == 3 && args[0]->IsNumber() && args[1]->IsString() && args[2]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[2]->ToString()); /* type: _14808  */
    

    self->AppendCheckItem(itemid, *text, *help);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44717
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    

    self->AppendCheckItem(itemid, *text);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: AppendCheckItem)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_AppendRadioItem(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44718
   */
  if(args.Length() == 3 && args[0]->IsNumber() && args[1]->IsString() && args[2]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[2]->ToString()); /* type: _14808  */
    

    self->AppendRadioItem(itemid, *text, *help);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44718
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    

    self->AppendRadioItem(itemid, *text);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: AppendRadioItem)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_AppendSubMenu(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44719
   */
  if(args.Length() == 3 && args[0]->IsObject() && args[1]->IsString() && args[2]->IsString()) {
    wxNode_wxMenu* submenu = wxNodeObject::unwrap<wxNode_wxMenu>(args[0]->ToObject()); /* type: _52838 * */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[2]->ToString()); /* type: _14808  */
    

    self->AppendSubMenu(submenu, *text, *help);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44719
   */
  if(args.Length() == 2 && args[0]->IsObject() && args[1]->IsString()) {
    wxNode_wxMenu* submenu = wxNodeObject::unwrap<wxNode_wxMenu>(args[0]->ToObject()); /* type: _52838 * */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    

    self->AppendSubMenu(submenu, *text);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: AppendSubMenu)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_Break(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44721
   */
  if(args.Length() == 0) {
    

    self->Break();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: Break)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_Insert(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44722
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsObject()) {
    unsigned int pos = (unsigned int)args[0]->ToInt32()->Value(); /* type: _8620  */
    wxNode_wxMenuItem* item = wxNodeObject::unwrap<wxNode_wxMenuItem>(args[1]->ToObject()); /* type: _51683 * */
    

    self->Insert(pos, item);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44723
   */
  if(args.Length() == 5 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsString() && args[3]->IsString() && args[4]->IsObject()) {
    unsigned int pos = (unsigned int)args[0]->ToInt32()->Value(); /* type: _8620  */
    int itemid = (int)args[1]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[2]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[3]->ToString()); /* type: _14808  */
    wxNode_wxItemKind* kind = wxNodeObject::unwrap<wxNode_wxItemKind>(args[4]->ToObject()); /* type: _4625  */
    

    self->Insert(pos, itemid, *text, *help, kind);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44723
   */
  if(args.Length() == 4 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsString() && args[3]->IsString()) {
    unsigned int pos = (unsigned int)args[0]->ToInt32()->Value(); /* type: _8620  */
    int itemid = (int)args[1]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[2]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[3]->ToString()); /* type: _14808  */
    

    self->Insert(pos, itemid, *text, *help);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44723
   */
  if(args.Length() == 3 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsString()) {
    unsigned int pos = (unsigned int)args[0]->ToInt32()->Value(); /* type: _8620  */
    int itemid = (int)args[1]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[2]->ToString()); /* type: _14808  */
    

    self->Insert(pos, itemid, *text);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44723
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsNumber()) {
    unsigned int pos = (unsigned int)args[0]->ToInt32()->Value(); /* type: _8620  */
    int itemid = (int)args[1]->ToInt32()->Value(); /* type: _162  */
    

    self->Insert(pos, itemid);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44727
   */
  if(args.Length() == 5 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsString() && args[3]->IsObject() && args[4]->IsString()) {
    unsigned int pos = (unsigned int)args[0]->ToInt32()->Value(); /* type: _8620  */
    int itemid = (int)args[1]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[2]->ToString()); /* type: _14808  */
    wxNode_wxMenu* submenu = wxNodeObject::unwrap<wxNode_wxMenu>(args[3]->ToObject()); /* type: _52838 * */
    v8::String::AsciiValue help(args[4]->ToString()); /* type: _14808  */
    

    self->Insert(pos, itemid, *text, submenu, *help);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44727
   */
  if(args.Length() == 4 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsString() && args[3]->IsObject()) {
    unsigned int pos = (unsigned int)args[0]->ToInt32()->Value(); /* type: _8620  */
    int itemid = (int)args[1]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[2]->ToString()); /* type: _14808  */
    wxNode_wxMenu* submenu = wxNodeObject::unwrap<wxNode_wxMenu>(args[3]->ToObject()); /* type: _52838 * */
    

    self->Insert(pos, itemid, *text, submenu);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44774
   */
  if(args.Length() == 5 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsString() && args[3]->IsString() && args[4]->IsBoolean()) {
    unsigned int pos = (unsigned int)args[0]->ToInt32()->Value(); /* type: _8620  */
    int itemid = (int)args[1]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[2]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[3]->ToString()); /* type: _14808  */
    bool isCheckable = args[4]->ToBoolean()->Value(); /* type: _14666  */
    

    self->Insert(pos, itemid, *text, *help, isCheckable);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: Insert)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_InsertSeparator(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44724
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    unsigned int pos = (unsigned int)args[0]->ToInt32()->Value(); /* type: _8620  */
    

    self->InsertSeparator(pos);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: InsertSeparator)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_InsertCheckItem(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44725
   */
  if(args.Length() == 4 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsString() && args[3]->IsString()) {
    unsigned int pos = (unsigned int)args[0]->ToInt32()->Value(); /* type: _8620  */
    int itemid = (int)args[1]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[2]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[3]->ToString()); /* type: _14808  */
    

    self->InsertCheckItem(pos, itemid, *text, *help);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44725
   */
  if(args.Length() == 3 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsString()) {
    unsigned int pos = (unsigned int)args[0]->ToInt32()->Value(); /* type: _8620  */
    int itemid = (int)args[1]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[2]->ToString()); /* type: _14808  */
    

    self->InsertCheckItem(pos, itemid, *text);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: InsertCheckItem)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_InsertRadioItem(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44726
   */
  if(args.Length() == 4 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsString() && args[3]->IsString()) {
    unsigned int pos = (unsigned int)args[0]->ToInt32()->Value(); /* type: _8620  */
    int itemid = (int)args[1]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[2]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[3]->ToString()); /* type: _14808  */
    

    self->InsertRadioItem(pos, itemid, *text, *help);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44726
   */
  if(args.Length() == 3 && args[0]->IsNumber() && args[1]->IsNumber() && args[2]->IsString()) {
    unsigned int pos = (unsigned int)args[0]->ToInt32()->Value(); /* type: _8620  */
    int itemid = (int)args[1]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[2]->ToString()); /* type: _14808  */
    

    self->InsertRadioItem(pos, itemid, *text);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: InsertRadioItem)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_Prepend(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44728
   */
  if(args.Length() == 1 && args[0]->IsObject()) {
    wxNode_wxMenuItem* item = wxNodeObject::unwrap<wxNode_wxMenuItem>(args[0]->ToObject()); /* type: _51683 * */
    

    self->Prepend(item);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44729
   */
  if(args.Length() == 4 && args[0]->IsNumber() && args[1]->IsString() && args[2]->IsString() && args[3]->IsObject()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[2]->ToString()); /* type: _14808  */
    wxNode_wxItemKind* kind = wxNodeObject::unwrap<wxNode_wxItemKind>(args[3]->ToObject()); /* type: _4625  */
    

    self->Prepend(itemid, *text, *help, kind);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44729
   */
  if(args.Length() == 3 && args[0]->IsNumber() && args[1]->IsString() && args[2]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[2]->ToString()); /* type: _14808  */
    

    self->Prepend(itemid, *text, *help);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44729
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    

    self->Prepend(itemid, *text);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44729
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    

    self->Prepend(itemid);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44733
   */
  if(args.Length() == 4 && args[0]->IsNumber() && args[1]->IsString() && args[2]->IsObject() && args[3]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    wxNode_wxMenu* submenu = wxNodeObject::unwrap<wxNode_wxMenu>(args[2]->ToObject()); /* type: _52838 * */
    v8::String::AsciiValue help(args[3]->ToString()); /* type: _14808  */
    

    self->Prepend(itemid, *text, submenu, *help);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44733
   */
  if(args.Length() == 3 && args[0]->IsNumber() && args[1]->IsString() && args[2]->IsObject()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    wxNode_wxMenu* submenu = wxNodeObject::unwrap<wxNode_wxMenu>(args[2]->ToObject()); /* type: _52838 * */
    

    self->Prepend(itemid, *text, submenu);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44775
   */
  if(args.Length() == 4 && args[0]->IsNumber() && args[1]->IsString() && args[2]->IsString() && args[3]->IsBoolean()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[2]->ToString()); /* type: _14808  */
    bool isCheckable = args[3]->ToBoolean()->Value(); /* type: _14666  */
    

    self->Prepend(itemid, *text, *help, isCheckable);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: Prepend)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_PrependSeparator(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44730
   */
  if(args.Length() == 0) {
    

    self->PrependSeparator();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: PrependSeparator)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_PrependCheckItem(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44731
   */
  if(args.Length() == 3 && args[0]->IsNumber() && args[1]->IsString() && args[2]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[2]->ToString()); /* type: _14808  */
    

    self->PrependCheckItem(itemid, *text, *help);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44731
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    

    self->PrependCheckItem(itemid, *text);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: PrependCheckItem)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_PrependRadioItem(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44732
   */
  if(args.Length() == 3 && args[0]->IsNumber() && args[1]->IsString() && args[2]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    v8::String::AsciiValue help(args[2]->ToString()); /* type: _14808  */
    

    self->PrependRadioItem(itemid, *text, *help);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44732
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue text(args[1]->ToString()); /* type: _14808  */
    

    self->PrependRadioItem(itemid, *text);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: PrependRadioItem)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_Remove(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44734
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    

    self->Remove(itemid);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44735
   */
  if(args.Length() == 1 && args[0]->IsObject()) {
    wxNode_wxMenuItem* item = wxNodeObject::unwrap<wxNode_wxMenuItem>(args[0]->ToObject()); /* type: _51683 * */
    

    self->Remove(item);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: Remove)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_Delete(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44736
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    

    self->Delete(itemid);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44737
   */
  if(args.Length() == 1 && args[0]->IsObject()) {
    wxNode_wxMenuItem* item = wxNodeObject::unwrap<wxNode_wxMenuItem>(args[0]->ToObject()); /* type: _51683 * */
    

    self->Delete(item);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: Delete)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_Destroy(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44738
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    

    self->Destroy(itemid);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44739
   */
  if(args.Length() == 1 && args[0]->IsObject()) {
    wxNode_wxMenuItem* item = wxNodeObject::unwrap<wxNode_wxMenuItem>(args[0]->ToObject()); /* type: _51683 * */
    

    self->Destroy(item);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: Destroy)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_GetMenuItemCount(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44740
   */
  if(args.Length() == 0) {
    

    self->GetMenuItemCount();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: GetMenuItemCount)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_GetMenuItems(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44741
   */
  if(args.Length() == 0) {
    

    self->GetMenuItems();

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44742
   */
  if(args.Length() == 0) {
    

    self->GetMenuItems();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: GetMenuItems)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_FindItem(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44743
   */
  if(args.Length() == 1 && args[0]->IsString()) {
    v8::String::AsciiValue item(args[0]->ToString()); /* type: _14808  */
    

    self->FindItem(*item);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44744
   */
  if(args.Length() == 2 && args[0]->IsNumber() && false) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    wxMenu* menu; /* type: _65194 ** */
    

    self->FindItem(itemid, &menu);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44744
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    

    self->FindItem(itemid);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: FindItem)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_FindItemByPosition(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44745
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    unsigned int position = (unsigned int)args[0]->ToInt32()->Value(); /* type: _8620  */
    

    self->FindItemByPosition(position);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: FindItemByPosition)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_Enable(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44746
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsBoolean()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    bool enable = args[1]->ToBoolean()->Value(); /* type: _14666  */
    

    self->Enable(itemid, enable);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: Enable)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_IsEnabled(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44747
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    

    self->IsEnabled(itemid);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: IsEnabled)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_Check(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44748
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsBoolean()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    bool check = args[1]->ToBoolean()->Value(); /* type: _14666  */
    

    self->Check(itemid, check);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: Check)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_IsChecked(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44749
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    

    self->IsChecked(itemid);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: IsChecked)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_SetLabel(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44750
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue label(args[1]->ToString()); /* type: _14808  */
    

    self->SetLabel(itemid, *label);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: SetLabel)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_GetLabel(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44751
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    

    self->GetLabel(itemid);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: GetLabel)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_GetLabelText(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44752
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    

    self->GetLabelText(itemid);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: GetLabelText)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_SetHelpString(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44753
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsString()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    v8::String::AsciiValue helpString(args[1]->ToString()); /* type: _14808  */
    

    self->SetHelpString(itemid, *helpString);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: SetHelpString)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_GetHelpString(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44754
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    

    self->GetHelpString(itemid);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: GetHelpString)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_SetTitle(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44755
   */
  if(args.Length() == 1 && args[0]->IsString()) {
    v8::String::AsciiValue title(args[0]->ToString()); /* type: _14808  */
    

    self->SetTitle(*title);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: SetTitle)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_GetTitle(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44756
   */
  if(args.Length() == 0) {
    

    self->GetTitle();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: GetTitle)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_SetEventHandler(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44757
   */
  if(args.Length() == 1 && args[0]->IsObject()) {
    wxNode_wxEvtHandler* handler = wxNodeObject::unwrap<wxNode_wxEvtHandler>(args[0]->ToObject()); /* type: _1665 * */
    

    self->SetEventHandler(handler);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: SetEventHandler)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_GetEventHandler(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44758
   */
  if(args.Length() == 0) {
    

    self->GetEventHandler();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: GetEventHandler)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_SetInvokingWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44759
   */
  if(args.Length() == 1 && args[0]->IsObject()) {
    wxNode_wxWindow* win = wxNodeObject::unwrap<wxNode_wxWindow>(args[0]->ToObject()); /* type: _993 * */
    

    self->SetInvokingWindow(win);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: SetInvokingWindow)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_GetInvokingWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44760
   */
  if(args.Length() == 0) {
    

    self->GetInvokingWindow();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: GetInvokingWindow)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_GetWindow(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44761
   */
  if(args.Length() == 0) {
    

    self->GetWindow();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: GetWindow)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_GetStyle(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44762
   */
  if(args.Length() == 0) {
    

    self->GetStyle();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: GetStyle)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_UpdateUI(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44763
   */
  if(args.Length() == 1 && args[0]->IsObject()) {
    wxNode_wxEvtHandler* source = wxNodeObject::unwrap<wxNode_wxEvtHandler>(args[0]->ToObject()); /* type: _1665 * */
    

    self->UpdateUI(source);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44763
   */
  if(args.Length() == 0) {
    

    self->UpdateUI();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: UpdateUI)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_GetMenuBar(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44764
   */
  if(args.Length() == 0) {
    

    self->GetMenuBar();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: GetMenuBar)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_Attach(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44765
   */
  if(args.Length() == 1 && args[0]->IsObject()) {
    wxNode_wxMenuBar* menubar = wxNodeObject::unwrap<wxNode_wxMenuBar>(args[0]->ToObject()); /* type: _59442 * */
    

    self->Attach(menubar);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: Attach)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_Detach(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44766
   */
  if(args.Length() == 0) {
    

    self->Detach();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: Detach)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_IsAttached(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44767
   */
  if(args.Length() == 0) {
    

    self->IsAttached();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: IsAttached)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_SetParent(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44768
   */
  if(args.Length() == 1 && args[0]->IsObject()) {
    wxNode_wxMenu* parent = wxNodeObject::unwrap<wxNode_wxMenu>(args[0]->ToObject()); /* type: _52838 * */
    

    self->SetParent(parent);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: SetParent)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_GetParent(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44769
   */
  if(args.Length() == 0) {
    

    self->GetParent();

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: GetParent)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_FindChildItem(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44770
   */
  if(args.Length() == 2 && args[0]->IsNumber() && false) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    unsigned int pos; /* type: _28691 * */
    

    self->FindChildItem(itemid, &pos);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44770
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    

    self->FindChildItem(itemid);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: FindChildItem)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_SendEvent(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44771
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsNumber()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    int checked = (int)args[1]->ToInt32()->Value(); /* type: _162  */
    

    self->SendEvent(itemid, checked);

    // TODO: handle return type
    return v8::Undefined();
  }
  
  /*
   * id: _44771
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int itemid = (int)args[0]->ToInt32()->Value(); /* type: _162  */
    

    self->SendEvent(itemid);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: SendEvent)."));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxMenu::_LockAccels(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxMenu* self = unwrap<wxNode_wxMenu>(args.This());

  
  /*
   * id: _44776
   */
  if(args.Length() == 1 && args[0]->IsBoolean()) {
    bool locked = args[0]->ToBoolean()->Value(); /* type: _14666  */
    

    self->LockAccels(locked);

    // TODO: handle return type
    return v8::Undefined();
  }
  

  return v8::ThrowException(v8::String::New("Could not find matching method for arguments (method name: LockAccels)."));
}

