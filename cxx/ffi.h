#include "quickjs/quickjs.h"

#ifdef _MSC_VER
#define DLLEXPORT __declspec(dllexport)
#else
#define DLLEXPORT __attribute__((visibility("default"))) __attribute__((used))
#endif

extern "C"
{

  typedef void *JSChannel(JSContext *ctx, const char *method, void *argv);

  DLLEXPORT JSValue *jsThrowInternalError(JSContext *ctx, char *message);

  DLLEXPORT JSValue *jsEXCEPTION();

  DLLEXPORT JSValue *jsUNDEFINED();

  DLLEXPORT JSValue *jsNULL();

  DLLEXPORT JSRuntime *jsNewRuntime(JSChannel channel);

  DLLEXPORT void jsFreeRuntime(JSRuntime *rt);

  DLLEXPORT JSContext *jsNewContext(JSRuntime *rt);

  DLLEXPORT void jsFreeContext(JSContext *ctx);

  DLLEXPORT JSRuntime *jsGetRuntime(JSContext *ctx);

  DLLEXPORT JSValue *jsEval(JSContext *ctx, const char *input, size_t input_len, const char *filename, int32_t eval_flags);

  DLLEXPORT int32_t jsValueGetTag(JSValue *val);

  DLLEXPORT void *jsValueGetPtr(JSValue *val);

  DLLEXPORT int32_t jsTagIsFloat64(int32_t tag);

  DLLEXPORT JSValue *jsNewBool(JSContext *ctx, int32_t val);

  DLLEXPORT JSValue *jsNewInt64(JSContext *ctx, int64_t val);

  DLLEXPORT JSValue *jsNewFloat64(JSContext *ctx, double val);

  DLLEXPORT JSValue *jsNewString(JSContext *ctx, const char *str);

  DLLEXPORT JSValue *jsNewArrayBufferCopy(JSContext *ctx, const uint8_t *buf, size_t len);

  DLLEXPORT JSValue *jsNewArray(JSContext *ctx);

  DLLEXPORT JSValue *jsNewObject(JSContext *ctx);

  DLLEXPORT void jsFreeValue(JSContext *ctx, JSValue *v, int32_t free);

  DLLEXPORT void jsFreeValueRT(JSRuntime *rt, JSValue *v, int32_t free);

  DLLEXPORT JSValue *jsDupValue(JSContext *ctx, JSValueConst *v);

  DLLEXPORT JSValue *jsDupValueRT(JSRuntime *rt, JSValue *v);

  DLLEXPORT int32_t jsToBool(JSContext *ctx, JSValueConst *val);

  DLLEXPORT int64_t jsToInt64(JSContext *ctx, JSValueConst *val);

  DLLEXPORT double jsToFloat64(JSContext *ctx, JSValueConst *val);

  DLLEXPORT const char *jsToCString(JSContext *ctx, JSValueConst *val);

  DLLEXPORT void jsFreeCString(JSContext *ctx, const char *ptr);

  DLLEXPORT uint8_t *jsGetArrayBuffer(JSContext *ctx, size_t *psize, JSValueConst *obj);

  DLLEXPORT int32_t jsIsFunction(JSContext *ctx, JSValueConst *val);

  DLLEXPORT int32_t jsIsPromise(JSContext *ctx, JSValueConst *val);

  DLLEXPORT int32_t jsIsArray(JSContext *ctx, JSValueConst *val);

  DLLEXPORT JSValue *jsGetProperty(JSContext *ctx, JSValueConst *this_obj,
                                   JSAtom prop);

  DLLEXPORT int32_t jsDefinePropertyValue(JSContext *ctx, JSValueConst *this_obj,
                                          JSAtom prop, JSValue *val, int32_t flags);

  DLLEXPORT void jsFreeAtom(JSContext *ctx, JSAtom v);

  DLLEXPORT JSAtom jsValueToAtom(JSContext *ctx, JSValueConst *val);

  DLLEXPORT JSValue *jsAtomToValue(JSContext *ctx, JSAtom val);

  DLLEXPORT int32_t jsGetOwnPropertyNames(JSContext *ctx, JSPropertyEnum **ptab,
                                          uint32_t *plen, JSValueConst *obj, int32_t flags);

  DLLEXPORT JSAtom jsPropertyEnumGetAtom(JSPropertyEnum *ptab, int32_t i);

  DLLEXPORT uint32_t sizeOfJSValue();

  DLLEXPORT void setJSValueList(JSValue *list, uint32_t i, JSValue *val);

  DLLEXPORT JSValue *jsCall(JSContext *ctx, JSValueConst *func_obj, JSValueConst *this_obj,
                            int32_t argc, JSValueConst *argv);

  DLLEXPORT int32_t jsIsException(JSValueConst *val);

  DLLEXPORT JSValue *jsGetException(JSContext *ctx);

  DLLEXPORT int32_t jsExecutePendingJob(JSRuntime *rt);

  DLLEXPORT JSValue *jsNewPromiseCapability(JSContext *ctx, JSValue *resolving_funcs);

  DLLEXPORT void jsFree(JSContext *ctx, void *ptab);
}