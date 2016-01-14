VariantDir('Debug', 'src', duplicate = 0)

env = Environment()

env.Append(CPPPATH=["Debug/patterns/proxy",
                    "Debug/patterns/singleton",
                    "Debug/patterns/factory_method",
                    "Debug/patterns/callback",
                    "Debug/standard_library",
                    "Debug/classes",
                    "Debug/system",
                    "Debug/types",
                    ])

src_files = ["Debug/learn_cpp.cpp"]

src_files_fields = ["Debug/classes/copy_operator.cpp",
                    "Debug/classes/slicing.cpp",
                    "Debug/patterns/proxy/proxy.cpp",
                    "Debug/patterns/singleton/singleton.cpp",
                    "Debug/patterns/factory_method/factory_method.cpp",
                    "Debug/patterns/callback/callback.cpp",
                    "Debug/standard_library/erase_remove.cpp",
                    "Debug/standard_library/copy_objects_3.cpp",
                    "Debug/standard_library/size_empty_splice.cpp",
                    "Debug/standard_library/assign.cpp",
                    "Debug/standard_library/equal_equivalent.cpp",
                    "Debug/standard_library/sort.cpp",
                    "Debug/system/filesystem_basic.cpp",
                    "Debug/system/system_time.cpp",
                    "Debug/types/class_static.cpp",
                    "Debug/types/enum.cpp"
                    ]
                    
src_files += src_files_fields

src_files_layers = []

src_files += src_files_layers

src_files_packets = []

src_files += src_files_packets

env.Program(source = src_files, LIBS = ['gtest', 'gtest_main', 'pthread', 'libssl', 'libcrypto'], LIBPATH = ['usr/lib'])