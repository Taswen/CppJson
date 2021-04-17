#ifndef _CPPJSON_H_
#define _CPPJSON_H_

namespace json {

enum JSONVALUETYPE {
    VALUETYPE_NULL,   // 空类型
    VALUETYPE_BOOL,   // 布尔类型
    VALUETYPE_NUMBER, // 数字类型
    VALUETYPE_STRING, // 字符串类型
    VALUETYPE_LIST,   // 列表
    VALUETYPE_OBJECT,   // 字典
};

enum JSONPARSERESULT:int{
    PARSERESULT_OK =0,
    PARSERESULT_EXPECT,
    PARSERESULT_INVALID_VALUE,
    PARSERESULT_ROOT_NOT_SINGULAR
};

class JsonValue {
  private:
    JSONVALUETYPE type;

  public:
    void setType(JSONVALUETYPE t);
    JSONVALUETYPE getType();
};

class JsonParser {
  public:
    /**
     * @arg v 
     * @arg json
     */
    static int Parese(JsonValue* v,const char *json);
};

}; // namespace json

#endif // _CPPJSON_H_