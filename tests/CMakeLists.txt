add_executable(LLTest
               LL.test.cpp
               ../src/App/IModelProvider.h
               ../src/App/LLParser.cpp
               ../src/App/LLParser.h
               ../src/App/IInputReader.h
               ../src/Infrastructure/ModelProvider.cpp
               ../src/Infrastructure/ModelProvider.h
               ../src/Infrastructure/InputReader.cpp
               ../src/Infrastructure/InputReader.h)

target_link_libraries(LLTest PUBLIC catch2)
add_test(NAME LLTest COMMAND LLTest)
