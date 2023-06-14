# Cannot use cmake_policy(SET CMP0077 NEW) and then use set command to override options, 
# because subproject will use cmake_minimum_required and cmake policies will be reset
cmake_policy(SET CMP0077 OLD)
function(SET_OPTION OPT_NAME OPT_VAL)
  option(${OPT_NAME} "Options hard-coded by scripts" ${OPT_VAL})
  set(${OPT_NAME} ${OPT_VAL} PARENT_SCOPE)
endfunction()