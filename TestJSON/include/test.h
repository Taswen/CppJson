#ifndef _TEST_H_
#define _TEST_H_

#include <cstdio>
#include <vector>
#include <algorithm>
using std::vector;


// enum ERRORTYPE{
    
// }

#define EXPECT_EQ_BASE(equality,expect,actual,format,typeStr)\
    do{\
        if(!equality) {\
            fprintf(stderr,typeStr "%s:%d: Expect:" format " actual:" format "\n" , __FILE__,__LINE__,expect,actual);\
            throw typeStr;\
        }\
    }while(0);
#define EXPECT_EQ_INT(expect,actual) EXPECT_EQ_BASE((expect)==(actual),expect,actual,"%d","[Int Not Equal] ")


class JsonTest{
private:
    int mainReturn;
    int testCount;
    int testPass;

    vector<int(*)()> testList;

    virtual void onFail();

public:

    /**
     * 添加测试
     */ 
    void addTest(int(*)());
    /**
     * 移除测试
     */ 
    void removeTest(int(*)());
    /**
     * 运行所有测试
     */ 
    void runTests();


};


#endif // _TEST_H_