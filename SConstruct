VariantDir('Debug', 'src', duplicate = 0)

env = Environment()

env.Append(CPPPATH=["Debug/patterns/proxy",
                    "Debug/patterns/singleton",
                    "Debug/patterns/factory_method",
                    "Debug/filesystem",
                    ])

src_files = ["Debug/learn_cpp.cpp"]

src_files_fields = ["Debug/patterns/proxy/proxy.cpp",
                    "Debug/patterns/singleton/singleton.cpp",
                    "Debug/patterns/factory_method/factory_method.cpp",
                    "Debug/filesystem/filesystem_basic.cpp",
                    ]
                    
src_files += src_files_fields

src_files_layers = []

src_files += src_files_layers

src_files_packets = []

src_files += src_files_packets

env.Program(source = src_files, LIBS = ['gtest', 'gtest_main', 'pthread'], LIBPATH = ['usr/lib'])