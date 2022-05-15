add_subdirectory(JSUMDUZE)

add_custom_target(SpojSumDuze
                  COMMAND "./JSUMDUZE/JSUMDUZETest"
                  DEPENDS JSUMDUZETest)