
#include <sstream>
#include "wxNode_wxSize.h"
#include "wxNode_wxPoint.h"


/* static */ v8::Persistent<v8::FunctionTemplate> wxNode_wxSize::s_ct;



wxNode_wxSize::wxNode_wxSize(wxSize& arg0)
  : wxSize(arg0)
{

}

wxNode_wxSize::wxNode_wxSize()
  : wxSize()
{

}

wxNode_wxSize::wxNode_wxSize(int xx, int yy)
  : wxSize(xx, yy)
{

}




/*static*/ void wxNode_wxSize::Init(v8::Handle<v8::Object> target) {
  v8::HandleScope scope;

  v8::Local<v8::FunctionTemplate> t = v8::FunctionTemplate::New(wxNodeObject::NewFunc);
  s_ct = v8::Persistent<v8::FunctionTemplate>::New(t);
  s_ct->InstanceTemplate()->SetInternalFieldCount(2);
  s_ct->SetClassName(v8::String::NewSymbol("wxSize"));

  NODE_SET_PROTOTYPE_METHOD(s_ct, "init", _init);
  AddMethods(s_ct);

  target->Set(v8::String::NewSymbol("wxSize"), s_ct->GetFunction());
}

/*static*/ void wxNode_wxSize::AddMethods(v8::Handle<v8::FunctionTemplate> target) {
  wxNode_wxEvtHandler::AddMethods(target);
  NODE_SET_PROTOTYPE_METHOD(target, "incTo", _IncTo);
  NODE_SET_PROTOTYPE_METHOD(target, "decTo", _DecTo);
  NODE_SET_PROTOTYPE_METHOD(target, "incBy", _IncBy);
  NODE_SET_PROTOTYPE_METHOD(target, "decBy", _DecBy);
  NODE_SET_PROTOTYPE_METHOD(target, "scale", _Scale);
  NODE_SET_PROTOTYPE_METHOD(target, "set", _Set);
  NODE_SET_PROTOTYPE_METHOD(target, "setWidth", _SetWidth);
  NODE_SET_PROTOTYPE_METHOD(target, "setHeight", _SetHeight);
  NODE_SET_PROTOTYPE_METHOD(target, "getWidth", _GetWidth);
  NODE_SET_PROTOTYPE_METHOD(target, "getHeight", _GetHeight);
  NODE_SET_PROTOTYPE_METHOD(target, "isFullySpecified", _IsFullySpecified);
  NODE_SET_PROTOTYPE_METHOD(target, "setDefaults", _SetDefaults);
  NODE_SET_PROTOTYPE_METHOD(target, "getX", _GetX);
  NODE_SET_PROTOTYPE_METHOD(target, "getY", _GetY);
  
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::New(wxNode_wxSize* obj) {
  v8::HandleScope scope;

  if(obj == NULL) {
    return scope.Close(v8::Null());
  }
  
  v8::Local<v8::FunctionTemplate> returnObjFt = v8::FunctionTemplate::New(wxNodeObject::NewFunc);
  returnObjFt->InstanceTemplate()->SetInternalFieldCount(2);
  returnObjFt->SetClassName(v8::String::NewSymbol("wxSize"));
  wxNode_wxSize::AddMethods(returnObjFt);

  v8::Local<v8::Function> returnObjFn = returnObjFt->GetFunction();
  v8::Handle<v8::Value> returnObjArgs[0];
  v8::Local<v8::Object> returnObj = returnObjFn->CallAsConstructor(0, returnObjArgs)->ToObject();
  returnObj->SetPointerInInternalField(0, obj);
  NodeExEvtHandlerImpl* evtHandler = dynamic_cast<NodeExEvtHandlerImpl*>(obj);
  returnObj->SetPointerInInternalField(1, evtHandler);

  return scope.Close(returnObj);
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::New(wxSize* obj) {
  v8::HandleScope scope;

  if(obj == NULL) {
    return scope.Close(v8::Null());
  }
  
  v8::Local<v8::FunctionTemplate> returnObjFt = v8::FunctionTemplate::New(wxNodeObject::NewFunc);
  returnObjFt->InstanceTemplate()->SetInternalFieldCount(2);
  returnObjFt->SetClassName(v8::String::NewSymbol("wxSize"));
  wxNode_wxSize::AddMethods(returnObjFt);

  v8::Local<v8::Function> returnObjFn = returnObjFt->GetFunction();
  v8::Handle<v8::Value> returnObjArgs[0];
  v8::Local<v8::Object> returnObj = returnObjFn->CallAsConstructor(0, returnObjArgs)->ToObject();
  returnObj->SetPointerInInternalField(0, obj);
  returnObj->SetPointerInInternalField(1, new NodeExEvtHandlerImplWrap(returnObj));

  return scope.Close(returnObj);
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::NewCopy(wxSize& obj) {
  v8::HandleScope scope;
  wxNode_wxSize* returnVal = new wxNode_wxSize();
  memcpy(dynamic_cast<wxSize*>(returnVal), &obj, sizeof(wxSize));
  return scope.Close(New(returnVal));

}

/*static*/ bool wxNode_wxSize::AssignableFrom(const v8::Handle<v8::String>& className) {
  v8::String::AsciiValue classNameStr(className);
  return AssignableFrom(*classNameStr);
}

/*static*/ bool wxNode_wxSize::AssignableFrom(const char* className) {
  if(!strcmp("wxSize", className)) { return true; }
  

  return false;
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_init(const v8::Arguments& args) {
  v8::HandleScope scope;

  
  
  /*
   * id: _59071
   */
  if(args.Length() == 1 && (args[0]->IsNull() || (args[0]->IsObject() && wxNode_wxSize::AssignableFrom(args[0]->ToObject()->GetConstructorName())))) {
    wxNode_wxSize* arg0 = args[0]->IsNull() ? NULL : wxNodeObject::unwrap<wxNode_wxSize>(args[0]->ToObject()); /* type: _25379  */
    

    wxNode_wxSize *self = new wxNode_wxSize(*arg0);
    NodeExEvtHandlerImpl* evtHandler = dynamic_cast<NodeExEvtHandlerImpl*>(self);
    self->wrap(args.This(), self, evtHandler);
    return args.This();
  }
  
  /*
   * id: _59072
   */
  if(args.Length() == 0) {
    

    wxNode_wxSize *self = new wxNode_wxSize();
    NodeExEvtHandlerImpl* evtHandler = dynamic_cast<NodeExEvtHandlerImpl*>(self);
    self->wrap(args.This(), self, evtHandler);
    return args.This();
  }
  
  /*
   * id: _59073
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsNumber()) {
    int xx = (int)args[0]->ToInt32()->Value(); /* type: _233  */
    int yy = (int)args[1]->ToInt32()->Value(); /* type: _233  */
    

    wxNode_wxSize *self = new wxNode_wxSize(xx, yy);
    NodeExEvtHandlerImpl* evtHandler = dynamic_cast<NodeExEvtHandlerImpl*>(self);
    self->wrap(args.This(), self, evtHandler);
    return args.This();
  }
  
  

  std::ostringstream errStr;
  errStr << "Could not find matching constructor for arguments (class name: wxSize).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}


/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_IncTo(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxSize* self = unwrap<wxNode_wxSize>(args.This());

  
  /*
   * id: _59086
   */
  if(args.Length() == 1 && (args[0]->IsNull() || (args[0]->IsObject() && wxNode_wxSize::AssignableFrom(args[0]->ToObject()->GetConstructorName())))) {
    wxNode_wxSize* sz = args[0]->IsNull() ? NULL : wxNodeObject::unwrap<wxNode_wxSize>(args[0]->ToObject()); /* type: _25379  */
    

    self->IncTo(*sz);

    return v8::Undefined();
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: wxSize::IncTo).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_DecTo(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxSize* self = unwrap<wxNode_wxSize>(args.This());

  
  /*
   * id: _59087
   */
  if(args.Length() == 1 && (args[0]->IsNull() || (args[0]->IsObject() && wxNode_wxSize::AssignableFrom(args[0]->ToObject()->GetConstructorName())))) {
    wxNode_wxSize* sz = args[0]->IsNull() ? NULL : wxNodeObject::unwrap<wxNode_wxSize>(args[0]->ToObject()); /* type: _25379  */
    

    self->DecTo(*sz);

    return v8::Undefined();
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: wxSize::DecTo).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_IncBy(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxSize* self = unwrap<wxNode_wxSize>(args.This());

  
  /*
   * id: _59088
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsNumber()) {
    int dx = (int)args[0]->ToInt32()->Value(); /* type: _233  */
    int dy = (int)args[1]->ToInt32()->Value(); /* type: _233  */
    

    self->IncBy(dx, dy);

    return v8::Undefined();
  }
  
  /*
   * id: _59089
   */
  if(args.Length() == 1 && (args[0]->IsNull() || (args[0]->IsObject() && wxNode_wxPoint::AssignableFrom(args[0]->ToObject()->GetConstructorName())))) {
    wxNode_wxPoint* pt = args[0]->IsNull() ? NULL : wxNodeObject::unwrap<wxNode_wxPoint>(args[0]->ToObject()); /* type: _25270  */
    

    self->IncBy(*pt);

    return v8::Undefined();
  }
  
  /*
   * id: _59090
   */
  if(args.Length() == 1 && (args[0]->IsNull() || (args[0]->IsObject() && wxNode_wxSize::AssignableFrom(args[0]->ToObject()->GetConstructorName())))) {
    wxNode_wxSize* sz = args[0]->IsNull() ? NULL : wxNodeObject::unwrap<wxNode_wxSize>(args[0]->ToObject()); /* type: _25379  */
    

    self->IncBy(*sz);

    return v8::Undefined();
  }
  
  /*
   * id: _59091
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int d = (int)args[0]->ToInt32()->Value(); /* type: _233  */
    

    self->IncBy(d);

    return v8::Undefined();
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: wxSize::IncBy).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_DecBy(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxSize* self = unwrap<wxNode_wxSize>(args.This());

  
  /*
   * id: _59092
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsNumber()) {
    int dx = (int)args[0]->ToInt32()->Value(); /* type: _233  */
    int dy = (int)args[1]->ToInt32()->Value(); /* type: _233  */
    

    self->DecBy(dx, dy);

    return v8::Undefined();
  }
  
  /*
   * id: _59093
   */
  if(args.Length() == 1 && (args[0]->IsNull() || (args[0]->IsObject() && wxNode_wxPoint::AssignableFrom(args[0]->ToObject()->GetConstructorName())))) {
    wxNode_wxPoint* pt = args[0]->IsNull() ? NULL : wxNodeObject::unwrap<wxNode_wxPoint>(args[0]->ToObject()); /* type: _25270  */
    

    self->DecBy(*pt);

    return v8::Undefined();
  }
  
  /*
   * id: _59094
   */
  if(args.Length() == 1 && (args[0]->IsNull() || (args[0]->IsObject() && wxNode_wxSize::AssignableFrom(args[0]->ToObject()->GetConstructorName())))) {
    wxNode_wxSize* sz = args[0]->IsNull() ? NULL : wxNodeObject::unwrap<wxNode_wxSize>(args[0]->ToObject()); /* type: _25379  */
    

    self->DecBy(*sz);

    return v8::Undefined();
  }
  
  /*
   * id: _59095
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int d = (int)args[0]->ToInt32()->Value(); /* type: _233  */
    

    self->DecBy(d);

    return v8::Undefined();
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: wxSize::DecBy).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_Scale(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxSize* self = unwrap<wxNode_wxSize>(args.This());

  
  /*
   * id: _59096
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsNumber()) {
    float xscale = (float)args[0]->ToNumber()->Value(); /* type: _1794  */
    float yscale = (float)args[1]->ToNumber()->Value(); /* type: _1794  */
    

    wxSize returnVal = self->Scale(xscale, yscale);

    return scope.Close(wxNode_wxSize::NewCopy(returnVal));
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: wxSize::Scale).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_Set(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxSize* self = unwrap<wxNode_wxSize>(args.This());

  
  /*
   * id: _59097
   */
  if(args.Length() == 2 && args[0]->IsNumber() && args[1]->IsNumber()) {
    int xx = (int)args[0]->ToInt32()->Value(); /* type: _233  */
    int yy = (int)args[1]->ToInt32()->Value(); /* type: _233  */
    

    self->Set(xx, yy);

    return v8::Undefined();
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: wxSize::Set).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_SetWidth(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxSize* self = unwrap<wxNode_wxSize>(args.This());

  
  /*
   * id: _59098
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int w = (int)args[0]->ToInt32()->Value(); /* type: _233  */
    

    self->SetWidth(w);

    return v8::Undefined();
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: wxSize::SetWidth).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_SetHeight(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxSize* self = unwrap<wxNode_wxSize>(args.This());

  
  /*
   * id: _59099
   */
  if(args.Length() == 1 && args[0]->IsNumber()) {
    int h = (int)args[0]->ToInt32()->Value(); /* type: _233  */
    

    self->SetHeight(h);

    return v8::Undefined();
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: wxSize::SetHeight).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_GetWidth(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxSize* self = unwrap<wxNode_wxSize>(args.This());

  
  /*
   * id: _59100
   */
  if(args.Length() == 0) {
    

    int returnVal = self->GetWidth();

    return scope.Close(v8::Number::New(returnVal));
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: wxSize::GetWidth).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_GetHeight(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxSize* self = unwrap<wxNode_wxSize>(args.This());

  
  /*
   * id: _59101
   */
  if(args.Length() == 0) {
    

    int returnVal = self->GetHeight();

    return scope.Close(v8::Number::New(returnVal));
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: wxSize::GetHeight).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_IsFullySpecified(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxSize* self = unwrap<wxNode_wxSize>(args.This());

  
  /*
   * id: _59102
   */
  if(args.Length() == 0) {
    

    bool returnVal = self->IsFullySpecified();

    return scope.Close(v8::Boolean::New(returnVal));
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: wxSize::IsFullySpecified).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_SetDefaults(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxSize* self = unwrap<wxNode_wxSize>(args.This());

  
  /*
   * id: _59103
   */
  if(args.Length() == 1 && (args[0]->IsNull() || (args[0]->IsObject() && wxNode_wxSize::AssignableFrom(args[0]->ToObject()->GetConstructorName())))) {
    wxNode_wxSize* size = args[0]->IsNull() ? NULL : wxNodeObject::unwrap<wxNode_wxSize>(args[0]->ToObject()); /* type: _25379  */
    

    self->SetDefaults(*size);

    return v8::Undefined();
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: wxSize::SetDefaults).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_GetX(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxSize* self = unwrap<wxNode_wxSize>(args.This());

  
  /*
   * id: _59104
   */
  if(args.Length() == 0) {
    

    int returnVal = self->GetX();

    return scope.Close(v8::Number::New(returnVal));
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: wxSize::GetX).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

/*static*/ v8::Handle<v8::Value> wxNode_wxSize::_GetY(const v8::Arguments& args) {
  v8::HandleScope scope;
  wxNode_wxSize* self = unwrap<wxNode_wxSize>(args.This());

  
  /*
   * id: _59105
   */
  if(args.Length() == 0) {
    

    int returnVal = self->GetY();

    return scope.Close(v8::Number::New(returnVal));
  }
  

  std::ostringstream errStr;
  errStr << "Could not find matching method for arguments (method name: wxSize::GetY).\n";
  errStr << "  arg count: " << args.Length() << "\n";
  for(int i = 0; i < args.Length(); i++) {
    v8::String::AsciiValue argStr(args[i]);
    errStr << "  arg[" << i << "]: " << *argStr << "\n";
  }
  return v8::ThrowException(v8::Exception::TypeError(v8::String::New(errStr.str().c_str())));
}

