#include "cppJson.h"
#include <cassert>
#include <algorithm>
namespace json {


#define EQ_TO_WHITESPACE(c)                                                    \
    ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r')


void JsonValue::setType(JSONVALUETYPE t){type = t;}
JSONVALUETYPE JsonValue::getType() { return type; }



// 不同数据类型变量的get和set函数
double JsonValue::getNumber(){
    assert(this->type == VALUETYPE_NUMBER);
    return this->value.n;
}

void JsonValue::setNumber(double n){

}

/// TODO
int JsonValue::getBoolean(){
    return 0;
}

void JsonValue::setBoolean(int b){

}

/// TODO
string JsonValue::getString(){

    return "";
}

/// TODO
size_t JsonValue::getStringLength(){
    
    return 0;
}

void JsonValue::setString(const char *s){
    assert(s != NULL);
    assert(this->type == VALUETYPE_STRING);
    this->value.s = s;
    this->type = VALUETYPE_STRING;
}

void JsonValue::setString(const string s){
    assert(this->type == VALUETYPE_STRING);
    this->value.s = s;
    this->type = VALUETYPE_STRING;
}

void JsonParser::_parseWhiteSpace(){
    this->json.erase(remove_if(this->json.begin(),this->json.end(),[](char & v){
      return EQ_TO_WHITESPACE(v);  
    }),this->json.end());
}

int JsonParser::parse(JsonValue* v,const char *json){
    assert(v != NULL);

    this->json = json;
    this->stack = NULL;
    this->size = this->top = 0;
    
    this->_parseWhiteSpace();
    v->setType(VALUETYPE_ERROR);

    int r = this->_parseValue(v);
    // 检测之后空白之后的有没有新的值
    if (r == PARSERESULT_OK) {
        char c = this->json[0];
        this->_parseWhiteSpace();
        if (this->json[0] != '\0') {
            if (c == this->json[0])
                r = PARSERESULT_INVALID_VALUE;
            else
                r = PARSERESULT_ROOT_NOT_SINGULAR;
            v->setType(VALUETYPE_ERROR);
        }
    }
    assert(this->top == 0);
    return r;
}


}; // namespace json