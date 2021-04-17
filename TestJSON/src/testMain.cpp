#include "cppJson.h"
#include "test.h"
/**
 * TDD 测试驱动用例
 */ 
using namespace json;

static int test_parse_null() {
    JsonValue v;
    v.setType(VALUETYPE_BOOL);
    EXPECT_EQ_INT(PARSERESULT_OK, JsonParser::Parese(&v, "null"));
    EXPECT_EQ_INT(VALUETYPE_NULL, v.getType());
    return 0;
}

static int test_parse() {
    int s = test_parse_null();
    return s;
}
int main(){
    JsonTest ts;
    ts.addTest(test_parse);
    ts.runTests();
    return 0;
}