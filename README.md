# CppJson
这是一个练手项目，目前处于开发的初级阶段。
This is practice project, and it's in the early stage of developments at present.
## Project Structure
```bash
│  .gitignore
│  CmakeLists.txt
│  LICENSE
│  README.md
│
├─bin                   #  生成的静态库
│
│
├─CppJSON               #  Json核心代码
│  │  CmakeLists.txt    
│  │
│  ├─include
│  │      cppJson.h
│  │
│  └─src
│         cppJson.cpp
│
├─test                  #  生成的测试程序
│      CppJSONTest.exe
│
└─TestJSON              #  TDD功能测试框架
    │  CmakeLists.txt
    │
    ├─include
    │      test.h
    │
    └─src
            test.cpp
            testMain.cpp
```

## Task
- [ ] 测试框架
    - [ ] 功能测试
        - [x] 初步搭建
        - [ ] 较为完善
        - [ ] 可以了
    - [ ] 单元测试
- [ ] Json解析功能
- [ ] Json操纵
- [ ] Json持久化
