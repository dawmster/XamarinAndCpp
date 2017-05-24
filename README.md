# Xamarin And C++
This is an attempt at using C++ library (.a) in Visual Studio for Mac (a.k.a. Xamarin)

### Contents
1) MyCppLib - XCode project
1) XamarinMacApp - Visual Studio For Mac solution
1) libMyCppLib.a - that is a product of MyCppLib (last build step copies the product here, and XamarinMacApp references it)

## What is ok
*MyCppLib* compiles fine and produces libMyCppLib.a
I intended to export only two C functions (my_C_Function, my_second_C_Function).
But I am unable to strip other sybols - which seems to be root of the problem

```C++    
    extern "C" {
        int my_C_Function();
        int my_second_C_Function();
    }
```

## What's not ok   
### XamarinMacApp - does not compile with following error :
Notice that C functions ( my_C_Function, my_second_C_Function is not listed in error below).
It seems only C++ Standard Library cannot be linked.

```

Undefined symbols for architecture x86_64:
      "std::__1::locale::use_facet(std::__1::locale::id&) const", referenced from:
          l004 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
          l005 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "std::__1::ios_base::getloc() const", referenced from:
          l004 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
          l005 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::__init(unsigned long, char)", referenced from:
          l007 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >::~basic_string()", referenced from:
          l007 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "std::__1::basic_ostream<char, std::__1::char_traits<char> >::put(char)", referenced from:
          l004 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "std::__1::basic_ostream<char, std::__1::char_traits<char> >::flush()", referenced from:
          l004 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry::sentry(std::__1::basic_ostream<char, std::__1::char_traits<char> >&)", referenced from:
          l005 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "std::__1::basic_ostream<char, std::__1::char_traits<char> >::sentry::~sentry()", referenced from:
          l005 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "std::__1::cout", referenced from:
          l002 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "std::__1::ctype<char>::id", referenced from:
          l004 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
          l005 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "std::__1::locale::~locale()", referenced from:
          l004 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
          l005 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "std::__1::ios_base::__set_badbit_and_consider_rethrow()", referenced from:
          l005 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "std::__1::ios_base::clear(unsigned int)", referenced from:
          l005 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "std::terminate()", referenced from:
          l008 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "operator delete(void*)", referenced from:
          l001 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "operator new(unsigned long)", referenced from:
          l001 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "___cxa_begin_catch", referenced from:
          l005 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
          l008 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "___cxa_end_catch", referenced from:
          l005 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
      "___gxx_personality_v0", referenced from:
          l004 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
          l005 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
          l007 in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
          Dwarf Exception Unwind Info (__eh_frame) in libMyCppLib.a(libMyCppLib.a-x86_64-master.o)
    ld: symbol(s) not found for architecture x86_64
    clang : error : linker command failed with exit code 1 (use -v to see invocation)
    
    MMP : error MM5109: Native linking failed with error code 1.  Check build log for details.
Done building target "_CompileToNative" in project "XamarinMacApp.csproj" -- FAILED.

Done building project "XamarinMacApp.csproj" -- FAILED.
```