# executable
set( EXE_NAME pputd )



# get source and include files
file( GLOB GPRTOOLS_SRC_FILES "*.c" "*.cpp" )
file( GLOB GPRTOOLS_INC_FILES "*.h" "../common/*.h" )



add_executable( ${EXE_NAME} ${GPRTOOLS_SRC_FILES} ${GPRTOOLS_INC_FILES} )


# add executable

# Linked libraries


# In order to use Carbon API, define qEnableCarbon in gpr_platform.h and uncomment code below 
# if (APPLE)
#	target_link_libraries( ${EXE_NAME} "-framework Carbon" )
# endif (APPLE)

# set the folder where to place the projects
#set_target_properties( ${EXE_NAME}  PROPERTIES FOLDER app )


