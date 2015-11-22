VariantDir('Debug', 'src', duplicate = 0)

env = Environment()

env.Append(CPPPATH=["Debug/patterns/proxy",
                    "Debug/filesystem"])

src_files = ["Debug/learn_cpp.cpp"]

src_files_fields = ["Debug/patterns/proxy/proxy.cpp",
                    "Debug/filesystem/filesystem_basic.cpp"]
                    
src_files += src_files_fields

src_files_layers = []

src_files += src_files_layers

src_files_packets = []

src_files += src_files_packets

env.Program(source = src_files, LIBS = ['gtest', 'gtest_main', 'pthread'], LIBPATH = ['usr/lib'])