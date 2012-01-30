
#include "wxnode.h"
#include "wxNodeObject.h"
#include "wxNodeClass.h"

v8::Handle<v8::Value> wxNodeObject::call(const char *fnName, int argc, v8::Handle<v8::Value> args[]) {
  v8::HandleScope scope;
  if(m_self.IsEmpty() || m_self->IsNull() || m_self->IsUndefined()) {
    // TODO: change to v8 error
    printf("ERROR: invalid object state. m_self is null\n");
  }
  v8::Local<v8::Value> fnObj = m_self->Get(v8::String::New(fnName));
  if(fnObj->IsNull() || fnObj->IsUndefined()) {
    // TODO: change to v8 error
    printf("ERROR: no method with name %s\n", fnName);
  }
  v8::Function *fn = v8::Function::Cast(*fnObj);
  return scope.Close(fn->Call(self(), argc, args));
}

/*static*/ void wxNodeObject::Init(v8::Handle<v8::FunctionTemplate>& ct) {
  NODE_SET_METHOD(ct, "extend", extend);
}

/*static*/ v8::Handle<v8::Value> wxNodeObject::extendCallHandler(const v8::Arguments& args) {
  v8::HandleScope scope;
  v8::Local<v8::Object> result;

  v8::Local<v8::Object> argsData = args.Data()->ToObject();
  v8::Handle<v8::Object> baseClass = argsData->Get(v8::String::New("baseClass"))->ToObject();
  v8::Handle<v8::Object> subClass = argsData->Get(v8::String::New("subClass"))->ToObject();

  // pass args
  v8::Local<v8::Value> argv[0];
  result = v8::Object::Cast(*baseClass->CallAsConstructor(0, argv));

  v8::Local<v8::Array> subClassPropNames = subClass->GetPropertyNames();
  for(uint32_t i=0; i<subClassPropNames->Length(); i++) {
    v8::Local<v8::String> propName = subClassPropNames->Get(i)->ToString();
    v8::Local<v8::Value> propVal = subClass->Get(propName);

    result->Set(propName, propVal);
  }

  // TODO: copy subClass methods

  return scope.Close(result);

  /*
  for (var name in prop) {
    // Check if we're overwriting an existing function
    prototype[name] = typeof prop[name] == "function" &&
      typeof _super[name] == "function" && fnTest.test(prop[name]) ?
      (function(name, fn){
        return function() {
          var tmp = this._super;

          // Add a new ._super() method that is the same method
          // but on the super-class
          this._super = _super[name];

          // The method only need to be bound temporarily, so we
          // remove it when we're done executing
          var ret = fn.apply(this, arguments);
          this._super = tmp;

          return ret;
        };
      })(name, prop[name]) :
      prop[name];
  }
  */

}


/*static*/ v8::Handle<v8::Value> wxNodeObject::extend(const v8::Arguments& args) {
  v8::HandleScope scope;
  v8::Handle<v8::Object> baseClass = args.This();
  v8::Handle<v8::Object> subClass = args[0]->ToObject();

  v8::Handle<v8::Object> data = v8::Object::New();
  data->Set(v8::String::New("baseClass"), baseClass);
  data->Set(v8::String::New("subClass"), subClass);

  v8::Local<v8::FunctionTemplate> t = v8::FunctionTemplate::New();
  t->SetCallHandler(extendCallHandler, data);
  t->InstanceTemplate()->SetInternalFieldCount(1);
  v8::Local<v8::Function> ctor = t->GetFunction();

  return scope.Close(ctor);
}