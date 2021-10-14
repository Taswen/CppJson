#ifndef _CPPJSON_H_
#define _CPPJSON_H_
#include <string>
using std::string;
namespace json {

enum JSONVALUETYPE {
    VALUETYPE_NULL,   // 空类型
    VALUETYPE_BOOL,   // 布尔类型
    VALUETYPE_NUMBER, // 数字类型
    VALUETYPE_STRING, // 字符串类型
    VALUETYPE_LIST,   // 列表
    VALUETYPE_OBJECT,   // 字典
    VALUETYPE_ERROR,   // 错误/或是空的类型，便于计算
};

enum JSONPARSERESULT:int{
    PARSERESULT_OK =0,
    PARSERESULT_EXPECT,           // 空白
    PARSERESULT_INVALID_VALUE,    // 值得类型非法
    PARSERESULT_ROOT_NOT_SINGULAR, // 根不唯一
    PARSERESULT_NUMBER_TOO_BIG     // 数值过大
};

class JsonValue {
  protected:
    // 类型
    JSONVALUETYPE type;
    // 值
    union {
      double n; // 数值型
      char* s; // 字符串类型
    } value;
    

    // // 辅助函数
    // void freeValue(){
    //   if (this->type == VALUETYPE_STRING)
    //       delete this->value.s.;
    //   this->type = VALUETYPE_ERROR;
    // }

  public:
    void setType(JSONVALUETYPE t);
    JSONVALUETYPE getType();

    // 不同数据类型变量的get和set函数
    double getNumber();

    void setNumber(double n);

    int getBoolean();

    void setBoolean(int b);

    string getString();
    size_t getStringLength();

    void setString(const char *s);
    void setString(const string s);

};

class JsonParser {
  private:
    string json;
    char* stack;
    int size, top;

  // protected:
  public:
    int _parseNumber();
    int _parseString();
    int _parseValue(JsonValue* v);
    void _parseWhiteSpace();

  public:
    int parse(JsonValue* v, const char *json);

};

}; // namespace json

#endif // _CPPJSON_H_