add_subdirectory(JSUMDUZE)

add_custom_target(test1
                  COMMAND "./JSUMDUZE/JSUMDUZETest"
                  DEPENDS JSUMDUZETest)