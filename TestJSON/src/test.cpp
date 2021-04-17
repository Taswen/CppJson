#include "test.h"


void JsonTest::addTest(int (*pf)()){
    testList.push_back(pf);
}
void JsonTest::removeTest(int(*pf)()){
    testList.erase(remove(testList.begin(),testList.end(),pf), testList.end());
}
void JsonTest::runTests(){
    testCount = testList.size();
    testPass = 0;
    for(auto i : testList){
        try{
            (*i)();
            testPass+=1;
        }catch(const char* errorMsg){
            onFail();
        }
    }
    if(testPass != testCount){
        printf("--------------------------\n");
        printf("Faild: %d/%d (%3.2f%%) passed\n", testPass, testCount, testPass * 100.0 / testCount);
    }else
        printf("All Success: %d passed\n", testCount);
}

void JsonTest::onFail(){}
