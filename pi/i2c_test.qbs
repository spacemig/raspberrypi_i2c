import qbs

CppApplication {
    consoleApplication: true
    files: ["main.cpp", "wiringPi/*"]

    Depends { name: 'cpp' }
    cpp.includePaths: [ 'wiringPi' ]
    cpp.staticLibraries: "pthread"
    //cpp.dynamicLibraries: "pthread"

    Group {     // Properties for the produced executable
        fileTagsFilter: product.type
        qbs.install: true
        qbs.installDir: "/home/pi/test"
    }
}
