#include "cppJson.h"
#include <cassert>
namespace json {


void JsonValue::setType(JSONVALUETYPE t){type = t;}
JSONVALUETYPE JsonValue::getType() { return type; }

int JsonParser::Parese(JsonValue* v,const char *json){
    assert(v!=nullptr);
    return  PARSERESULT_OK;
}

}; // namespace json