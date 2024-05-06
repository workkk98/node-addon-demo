#define NAPI_VERSION 8
#include <assert.h>
#include <node_api.h>

static int fabonacci(int n) {
  if (n == 1 || n == 2) {
    return 1;
  }
  return fabonacci(n - 1) + fabonacci(n - 2);
}

// Hello方法的实现，该方法返回hello
static napi_value Hello(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value world;

  status = napi_create_string_utf8(env, "hello-zhfcc", 12, &world);

  assert(status == napi_ok);

  return world;
}

static napi_value Fabonacci(napi_env env, napi_callback_info info) {
  napi_status status;
  napi_value world;

  int result = fabonacci(20);

  status = napi_create_int32(env, result, &world);

  assert(status == napi_ok);

  return world;
}

// typedef struct {
  // One of utf8name or name should be NULL.
//   const char* utf8name;
//   napi_value name;

//   napi_callback method;
//   napi_callback getter;
//   napi_callback setter;
//   napi_value value;

//   napi_property_attributes attributes;
//   void* data;
// } napi_property_descriptor;

#define DECLARE_NAPI_METHOD(name, func) \
  { name, 0, func, 0, 0, 0, napi_default, 0 }

static napi_value Init(napi_env env, napi_value exports) {
  napi_status status;

  napi_property_descriptor desc = DECLARE_NAPI_METHOD("hello", Hello); // 设置exports对象的描述结构体

  napi_property_descriptor desc2 = DECLARE_NAPI_METHOD("fabonacci", Fabonacci); // 设置exports对象的描述结构体
  // napi_property_descriptor desc2;

  napi_property_descriptor descs[] = {desc, desc2};

  status = napi_define_properties(env, exports, 2, descs); // env表示底层上下文的参数

  assert(status == napi_ok);

  return exports;
}

NAPI_MODULE(NODE_GYP_MODULE_NAME, Init) // 注册模块
