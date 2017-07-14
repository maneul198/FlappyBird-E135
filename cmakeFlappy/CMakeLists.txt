cmake_minimum_required( VERSION 3.0.0 FATAL_ERROR )

set( CMAKE_CXX_STANDARD 11 )

project( smart-vending-flappy-bird )

set( QT_MIN_VERSION "5.5.5" )

# Instruct CMake to run moc automatically when needed.
set( CMAKE_AUTOMOC ON )
# Find includes in corresponding build directories
set( CMAKE_INCLUDE_CURRENT_DIR ON )


find_package( Qt5  ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS
    Core QuickWidgets Multimedia
)

find_library(libdigitalio_dpx.so NAMES digitalio PATHS "/usr/local/lib/")

set(SRCS
    main.cpp
    mainwindow.cpp
    gameelement.cpp
    elebackground.cpp
    eleground.cpp
    elepipe.cpp
    elebird.cpp
    elescoreboard.cpp
    elereadyboard.cpp
    eleoverboard.cpp
    eletitleboard.cpp
    key.cpp
    awardPrize.cpp
    productsmanager.cpp
    product.cpp
    configurationFile.cpp
)

set( SRCH
    mainwindow.h
    gameelement.h
    elebackground.h
    eleground.h
    elepipe.h
    elebird.h
    elescoreboard.h
    elereadyboard.h
    eleoverboard.h
    eletitleboard.
    awardPrize.h
    productsmanager.h
    product.h
    myKeyEvents.h
    configurationFile.h
    key.h
)

add_executable(${PROJECT_NAME} ${RCC_SOURCES} ${SRCS} )

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::QuickWidgets
    Qt5::Multimedia
    #digitalio
    "/usr/local/lib/libdigitalio_dpx.so"
    "/usr/local/lib/libenginesv.so"
    "/usr/local/lib/libID003_LIB_V3.so"
    #"/home/smart/Documentos/qt_project/build-ID003_Lib_V3-Desktop-Debug/libID003_Lib_V3.so"
)

install( TARGETS ${PROJECT_NAME}  RUNTIME DESTINATION "bin" )
