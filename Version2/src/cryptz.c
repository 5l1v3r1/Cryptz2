/* Created By Benelhaj_Younes CopyRight */
/*Changing The Credits Doesn't Make you A Coder Nerd */

#define PY_SSIZE_T_CLEAN
#include "Python.h"
#ifndef Py_PYTHON_H
    #error Python headers needed to compile C extensions, please install development version of Python.
#elif PY_VERSION_HEX < 0x02060000 || (0x03000000 <= PY_VERSION_HEX && PY_VERSION_HEX < 0x03030000)
    #error Cython requires Python 2.6+ or Python 3.3+.
#else
#define CYTHON_ABI "0_29_13"
#define CYTHON_HEX_VERSION 0x001D0DF0
#define CYTHON_FUTURE_DIVISION 1
#include <stddef.h>
#ifndef offsetof
  #define offsetof(type, member) ( (size_t) & ((type*)0) -> member )
#endif
#if !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
  #ifndef __fastcall
    #define __fastcall
  #endif
#endif
#ifndef DL_IMPORT
  #define DL_IMPORT(t) t
#endif
#ifndef DL_EXPORT
  #define DL_EXPORT(t) t
#endif
#define __PYX_COMMA ,
#ifndef HAVE_LONG_LONG
  #if PY_VERSION_HEX >= 0x02070000
    #define HAVE_LONG_LONG
  #endif
#endif
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#ifndef Py_HUGE_VAL
  #define Py_HUGE_VAL HUGE_VAL
#endif
#ifdef PYPY_VERSION
  #define CYTHON_COMPILING_IN_PYPY 1
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #if PY_VERSION_HEX < 0x03050000
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#elif defined(PYSTON_VERSION)
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 1
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #undef CYTHON_USE_ASYNC_SLOTS
  #define CYTHON_USE_ASYNC_SLOTS 0
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#else
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 1
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYTYPE_LOOKUP
    #define CYTHON_USE_PYTYPE_LOOKUP 0
  #elif !defined(CYTHON_USE_PYTYPE_LOOKUP)
    #define CYTHON_USE_PYTYPE_LOOKUP 1
  #endif
  #if PY_MAJOR_VERSION < 3
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYLONG_INTERNALS
    #define CYTHON_USE_PYLONG_INTERNALS 0
  #elif !defined(CYTHON_USE_PYLONG_INTERNALS)
    #define CYTHON_USE_PYLONG_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_PYLIST_INTERNALS
    #define CYTHON_USE_PYLIST_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #if PY_VERSION_HEX < 0x030300F0
    #undef CYTHON_USE_UNICODE_WRITER
    #define CYTHON_USE_UNICODE_WRITER 0
  #elif !defined(CYTHON_USE_UNICODE_WRITER)
    #define CYTHON_USE_UNICODE_WRITER 1
  #endif
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #ifndef CYTHON_FAST_THREAD_STATE
    #define CYTHON_FAST_THREAD_STATE 1
  #endif
  #ifndef CYTHON_FAST_PYCALL
    #define CYTHON_FAST_PYCALL 1
  #endif
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT (PY_VERSION_HEX >= 0x03050000)
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE (PY_VERSION_HEX >= 0x030400a1)
  #endif
  #ifndef CYTHON_USE_DICT_VERSIONS
    #define CYTHON_USE_DICT_VERSIONS (PY_VERSION_HEX >= 0x030600B1)
  #endif
  #ifndef CYTHON_USE_EXC_INFO_STACK
    #define CYTHON_USE_EXC_INFO_STACK (PY_VERSION_HEX >= 0x030700A3)
  #endif
#endif
#if !defined(CYTHON_FAST_PYCCALL)
#define CYTHON_FAST_PYCCALL  (CYTHON_FAST_PYCALL && PY_VERSION_HEX >= 0x030600B1)
#endif
#if CYTHON_USE_PYLONG_INTERNALS
  #include "longintrepr.h"
  #undef SHIFT
  #undef BASE
  #undef MASK
  #ifdef SIZEOF_VOID_P
    enum { __pyx_check_sizeof_voidp = 1 / (int)(SIZEOF_VOID_P == sizeof(void*)) };
  #endif
#endif
#ifndef __has_attribute
  #define __has_attribute(x) 0
#endif
#ifndef __has_cpp_attribute
  #define __has_cpp_attribute(x) 0
#endif
#ifndef CYTHON_RESTRICT
  #if defined(__GNUC__)
    #define CYTHON_RESTRICT __restrict__
  #elif defined(_MSC_VER) && _MSC_VER >= 1400
    #define CYTHON_RESTRICT __restrict
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_RESTRICT restrict
  #else
    #define CYTHON_RESTRICT
  #endif
#endif
#ifndef CYTHON_UNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define CYTHON_UNUSED __attribute__ ((__unused__))
#   else
#     define CYTHON_UNUSED
#   endif
# elif defined(__ICC) || (defined(__INTEL_COMPILER) && !defined(_MSC_VER))
#   define CYTHON_UNUSED __attribute__ ((__unused__))
# else
#   define CYTHON_UNUSED
# endif
#endif
#ifndef CYTHON_MAYBE_UNUSED_VAR
#  if defined(__cplusplus)
     template<class T> void CYTHON_MAYBE_UNUSED_VAR( const T& ) { }
#  else
#    define CYTHON_MAYBE_UNUSED_VAR(x) (void)(x)
#  endif
#endif
#ifndef CYTHON_NCP_UNUSED
# if CYTHON_COMPILING_IN_CPYTHON
#  define CYTHON_NCP_UNUSED
# else
#  define CYTHON_NCP_UNUSED CYTHON_UNUSED
# endif
#endif
#define __Pyx_void_to_None(void_result) ((void)(void_result), Py_INCREF(Py_None), Py_None)
#ifdef _MSC_VER
    #ifndef _MSC_STDINT_H_
        #if _MSC_VER < 1300
           typedef unsigned char     uint8_t;
           typedef unsigned int      uint32_t;
        #else
           typedef unsigned __int8   uint8_t;
           typedef unsigned __int32  uint32_t;
        #endif
    #endif
#else
   #include <stdint.h>
#endif
#ifndef CYTHON_FALLTHROUGH
  #if defined(__cplusplus) && __cplusplus >= 201103L
    #if __has_cpp_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH [[fallthrough]]
    #elif __has_cpp_attribute(clang::fallthrough)
      #define CYTHON_FALLTHROUGH [[clang::fallthrough]]
    #elif __has_cpp_attribute(gnu::fallthrough)
      #define CYTHON_FALLTHROUGH [[gnu::fallthrough]]
    #endif
  #endif
  #ifndef CYTHON_FALLTHROUGH
    #if __has_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH __attribute__((fallthrough))
    #else
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
  #if defined(__clang__ ) && defined(__apple_build_version__)
    #if __apple_build_version__ < 7000000
      #undef  CYTHON_FALLTHROUGH
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
#endif

#ifndef CYTHON_INLINE
  #if defined(__clang__)
    #define CYTHON_INLINE __inline__ __attribute__ ((__unused__))
  #elif defined(__GNUC__)
    #define CYTHON_INLINE __inline__
  #elif defined(_MSC_VER)
    #define CYTHON_INLINE __inline
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_INLINE inline
  #else
    #define CYTHON_INLINE
  #endif
#endif

#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX < 0x02070600 && !defined(Py_OptimizeFlag)
  #define Py_OptimizeFlag 0
#endif
#define __PYX_BUILD_PY_SSIZE_T "n"
#define CYTHON_FORMAT_SSIZE_T "z"
#if PY_MAJOR_VERSION < 3
  #define __Pyx_BUILTIN_MODULE_NAME "__builtin__"
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a+k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
  #define __Pyx_DefaultClassType PyClass_Type
#else
  #define __Pyx_BUILTIN_MODULE_NAME "builtins"
#if PY_VERSION_HEX >= 0x030800A4 && PY_VERSION_HEX < 0x030800B2
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, 0, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#else
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#endif
  #define __Pyx_DefaultClassType PyType_Type
#endif
#ifndef Py_TPFLAGS_CHECKTYPES
  #define Py_TPFLAGS_CHECKTYPES 0
#endif
#ifndef Py_TPFLAGS_HAVE_INDEX
  #define Py_TPFLAGS_HAVE_INDEX 0
#endif
#ifndef Py_TPFLAGS_HAVE_NEWBUFFER
  #define Py_TPFLAGS_HAVE_NEWBUFFER 0
#endif
#ifndef Py_TPFLAGS_HAVE_FINALIZE
  #define Py_TPFLAGS_HAVE_FINALIZE 0
#endif
#ifndef METH_STACKLESS
  #define METH_STACKLESS 0
#endif
#if PY_VERSION_HEX <= 0x030700A3 || !defined(METH_FASTCALL)
  #ifndef METH_FASTCALL
     #define METH_FASTCALL 0x80
  #endif
  typedef PyObject *(*__Pyx_PyCFunctionFast) (PyObject *self, PyObject *const *args, Py_ssize_t nargs);
  typedef PyObject *(*__Pyx_PyCFunctionFastWithKeywords) (PyObject *self, PyObject *const *args,
                                                          Py_ssize_t nargs, PyObject *kwnames);
#else
  #define __Pyx_PyCFunctionFast _PyCFunctionFast
  #define __Pyx_PyCFunctionFastWithKeywords _PyCFunctionFastWithKeywords
#endif
#if CYTHON_FAST_PYCCALL
#define __Pyx_PyFastCFunction_Check(func)\
    ((PyCFunction_Check(func) && (METH_FASTCALL == (PyCFunction_GET_FLAGS(func) & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)))))
#else
#define __Pyx_PyFastCFunction_Check(func) 0
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Malloc)
  #define PyObject_Malloc(s)   PyMem_Malloc(s)
  #define PyObject_Free(p)     PyMem_Free(p)
  #define PyObject_Realloc(p)  PyMem_Realloc(p)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030400A1
  #define PyMem_RawMalloc(n)           PyMem_Malloc(n)
  #define PyMem_RawRealloc(p, n)       PyMem_Realloc(p, n)
  #define PyMem_RawFree(p)             PyMem_Free(p)
#endif
#if CYTHON_COMPILING_IN_PYSTON
  #define __Pyx_PyCode_HasFreeVars(co)  PyCode_HasFreeVars(co)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno) PyFrame_SetLineNumber(frame, lineno)
#else
  #define __Pyx_PyCode_HasFreeVars(co)  (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno)  (frame)->f_lineno = (lineno)
#endif
#if !CYTHON_FAST_THREAD_STATE || PY_VERSION_HEX < 0x02070000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#elif PY_VERSION_HEX >= 0x03060000
  #define __Pyx_PyThreadState_Current _PyThreadState_UncheckedGet()
#elif PY_VERSION_HEX >= 0x03000000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#else
  #define __Pyx_PyThreadState_Current _PyThreadState_Current
#endif
#if PY_VERSION_HEX < 0x030700A2 && !defined(PyThread_tss_create) && !defined(Py_tss_NEEDS_INIT)
#include "pythread.h"
#define Py_tss_NEEDS_INIT 0
typedef int Py_tss_t;
static CYTHON_INLINE int PyThread_tss_create(Py_tss_t *key) {
  *key = PyThread_create_key();
  return 0;
}
static CYTHON_INLINE Py_tss_t * PyThread_tss_alloc(void) {
  Py_tss_t *key = (Py_tss_t *)PyObject_Malloc(sizeof(Py_tss_t));
  *key = Py_tss_NEEDS_INIT;
  return key;
}
static CYTHON_INLINE void PyThread_tss_free(Py_tss_t *key) {
  PyObject_Free(key);
}
static CYTHON_INLINE int PyThread_tss_is_created(Py_tss_t *key) {
  return *key != Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE void PyThread_tss_delete(Py_tss_t *key) {
  PyThread_delete_key(*key);
  *key = Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE int PyThread_tss_set(Py_tss_t *key, void *value) {
  return PyThread_set_key_value(*key, value);
}
static CYTHON_INLINE void * PyThread_tss_get(Py_tss_t *key) {
  return PyThread_get_key_value(*key);
}
#endif
#if CYTHON_COMPILING_IN_CPYTHON || defined(_PyDict_NewPresized)
#define __Pyx_PyDict_NewPresized(n)  ((n <= 8) ? PyDict_New() : _PyDict_NewPresized(n))
#else
#define __Pyx_PyDict_NewPresized(n)  PyDict_New()
#endif
#if PY_MAJOR_VERSION >= 3 || CYTHON_FUTURE_DIVISION
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_TrueDivide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceTrueDivide(x,y)
#else
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_Divide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceDivide(x,y)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1 && CYTHON_USE_UNICODE_INTERNALS
#define __Pyx_PyDict_GetItemStr(dict, name)  _PyDict_GetItem_KnownHash(dict, name, ((PyASCIIObject *) name)->hash)
#else
#define __Pyx_PyDict_GetItemStr(dict, name)  PyDict_GetItem(dict, name)
#endif
#if PY_VERSION_HEX > 0x03030000 && defined(PyUnicode_KIND)
  #define CYTHON_PEP393_ENABLED 1
  #define __Pyx_PyUnicode_READY(op)       (likely(PyUnicode_IS_READY(op)) ?\
                                              0 : _PyUnicode_Ready((PyObject *)(op)))
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_LENGTH(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) PyUnicode_READ_CHAR(u, i)
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   PyUnicode_MAX_CHAR_VALUE(u)
  #define __Pyx_PyUnicode_KIND(u)         PyUnicode_KIND(u)
  #define __Pyx_PyUnicode_DATA(u)         PyUnicode_DATA(u)
  #define __Pyx_PyUnicode_READ(k, d, i)   PyUnicode_READ(k, d, i)
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  PyUnicode_WRITE(k, d, i, ch)
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : PyUnicode_GET_SIZE(u)))
#else
  #define CYTHON_PEP393_ENABLED 0
  #define PyUnicode_1BYTE_KIND  1
  #define PyUnicode_2BYTE_KIND  2
  #define PyUnicode_4BYTE_KIND  4
  #define __Pyx_PyUnicode_READY(op)       (0)
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_SIZE(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) ((Py_UCS4)(PyUnicode_AS_UNICODE(u)[i]))
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   ((sizeof(Py_UNICODE) == 2) ? 65535 : 1114111)
  #define __Pyx_PyUnicode_KIND(u)         (sizeof(Py_UNICODE))
  #define __Pyx_PyUnicode_DATA(u)         ((void*)PyUnicode_AS_UNICODE(u))
  #define __Pyx_PyUnicode_READ(k, d, i)   ((void)(k), (Py_UCS4)(((Py_UNICODE*)d)[i]))
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  (((void)(k)), ((Py_UNICODE*)d)[i] = ch)
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_SIZE(u))
#endif
#if CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyUnicode_Concat(a, b)      PyNumber_Add(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  PyNumber_Add(a, b)
#else
  #define __Pyx_PyUnicode_Concat(a, b)      PyUnicode_Concat(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  ((unlikely((a) == Py_None) || unlikely((b) == Py_None)) ?\
      PyNumber_Add(a, b) : __Pyx_PyUnicode_Concat(a, b))
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyUnicode_Contains)
  #define PyUnicode_Contains(u, s)  PySequence_Contains(u, s)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyByteArray_Check)
  #define PyByteArray_Check(obj)  PyObject_TypeCheck(obj, &PyByteArray_Type)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Format)
  #define PyObject_Format(obj, fmt)  PyObject_CallMethod(obj, "__format__", "O", fmt)
#endif
#define __Pyx_PyString_FormatSafe(a, b)   ((unlikely((a) == Py_None || (PyString_Check(b) && !PyString_CheckExact(b)))) ? PyNumber_Remainder(a, b) : __Pyx_PyString_Format(a, b))
#define __Pyx_PyUnicode_FormatSafe(a, b)  ((unlikely((a) == Py_None || (PyUnicode_Check(b) && !PyUnicode_CheckExact(b)))) ? PyNumber_Remainder(a, b) : PyUnicode_Format(a, b))
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyString_Format(a, b)  PyUnicode_Format(a, b)
#else
  #define __Pyx_PyString_Format(a, b)  PyString_Format(a, b)
#endif
#if PY_MAJOR_VERSION < 3 && !defined(PyObject_ASCII)
  #define PyObject_ASCII(o)            PyObject_Repr(o)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBaseString_Type            PyUnicode_Type
  #define PyStringObject               PyUnicodeObject
  #define PyString_Type                PyUnicode_Type
  #define PyString_Check               PyUnicode_Check
  #define PyString_CheckExact          PyUnicode_CheckExact
  #define PyObject_Unicode             PyObject_Str
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyBaseString_Check(obj) PyUnicode_Check(obj)
  #define __Pyx_PyBaseString_CheckExact(obj) PyUnicode_CheckExact(obj)
#else
  #define __Pyx_PyBaseString_Check(obj) (PyString_Check(obj) || PyUnicode_Check(obj))
  #define __Pyx_PyBaseString_CheckExact(obj) (PyString_CheckExact(obj) || PyUnicode_CheckExact(obj))
#endif
#ifndef PySet_CheckExact
  #define PySet_CheckExact(obj)        (Py_TYPE(obj) == &PySet_Type)
#endif
#if CYTHON_ASSUME_SAFE_MACROS
  #define __Pyx_PySequence_SIZE(seq)  Py_SIZE(seq)
#else
  #define __Pyx_PySequence_SIZE(seq)  PySequence_Size(seq)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyIntObject                  PyLongObject
  #define PyInt_Type                   PyLong_Type
  #define PyInt_Check(op)              PyLong_Check(op)
  #define PyInt_CheckExact(op)         PyLong_CheckExact(op)
  #define PyInt_FromString             PyLong_FromString
  #define PyInt_FromUnicode            PyLong_FromUnicode
  #define PyInt_FromLong               PyLong_FromLong
  #define PyInt_FromSize_t             PyLong_FromSize_t
  #define PyInt_FromSsize_t            PyLong_FromSsize_t
  #define PyInt_AsLong                 PyLong_AsLong
  #define PyInt_AS_LONG                PyLong_AS_LONG
  #define PyInt_AsSsize_t              PyLong_AsSsize_t
  #define PyInt_AsUnsignedLongMask     PyLong_AsUnsignedLongMask
  #define PyInt_AsUnsignedLongLongMask PyLong_AsUnsignedLongLongMask
  #define PyNumber_Int                 PyNumber_Long
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBoolObject                 PyLongObject
#endif
#if PY_MAJOR_VERSION >= 3 && CYTHON_COMPILING_IN_PYPY
  #ifndef PyUnicode_InternFromString
    #define PyUnicode_InternFromString(s) PyUnicode_FromString(s)
  #endif
#endif
#if PY_VERSION_HEX < 0x030200A4
  typedef long Py_hash_t;
  #define __Pyx_PyInt_FromHash_t PyInt_FromLong
  #define __Pyx_PyInt_AsHash_t   PyInt_AsLong
#else
  #define __Pyx_PyInt_FromHash_t PyInt_FromSsize_t
  #define __Pyx_PyInt_AsHash_t   PyInt_AsSsize_t
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyMethod_New(func, self, klass) ((self) ? PyMethod_New(func, self) : (Py_INCREF(func), func))
#else
  #define __Pyx_PyMethod_New(func, self, klass) PyMethod_New(func, self, klass)
#endif
#if CYTHON_USE_ASYNC_SLOTS
  #if PY_VERSION_HEX >= 0x030500B1
    #define __Pyx_PyAsyncMethodsStruct PyAsyncMethods
    #define __Pyx_PyType_AsAsync(obj) (Py_TYPE(obj)->tp_as_async)
  #else
    #define __Pyx_PyType_AsAsync(obj) ((__Pyx_PyAsyncMethodsStruct*) (Py_TYPE(obj)->tp_reserved))
  #endif
#else
  #define __Pyx_PyType_AsAsync(obj) NULL
#endif
#ifndef __Pyx_PyAsyncMethodsStruct
    typedef struct {
        unaryfunc am_await;
        unaryfunc am_aiter;
        unaryfunc am_anext;
    } __Pyx_PyAsyncMethodsStruct;
#endif

#if defined(WIN32) || defined(MS_WINDOWS)
  #define _USE_MATH_DEFINES
#endif
#include <math.h>
#ifdef NAN
#define __PYX_NAN() ((float) NAN)
#else
static CYTHON_INLINE float __PYX_NAN() {
  float value;
  memset(&value, 0xFF, sizeof(value));
  return value;
}
#endif
#if defined(__CYGWIN__) && defined(_LDBL_EQ_DBL)
#define __Pyx_truncl trunc
#else
#define __Pyx_truncl truncl
#endif


#define __PYX_ERR(f_index, lineno, Ln_error) \
{ \
  __pyx_filename = __pyx_f[f_index]; __pyx_lineno = lineno; __pyx_clineno = __LINE__; goto Ln_error; \
}

#ifndef __PYX_EXTERN_C
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

#define __PYX_HAVE__cryptz
#define __PYX_HAVE_API__cryptz
/* Early includes */
#ifdef _OPENMP
#include <omp.h>
#endif /* _OPENMP */

#if defined(PYREX_WITHOUT_ASSERTIONS) && !defined(CYTHON_WITHOUT_ASSERTIONS)
#define CYTHON_WITHOUT_ASSERTIONS
#endif

typedef struct {PyObject **p; const char *s; const Py_ssize_t n; const char* encoding;
                const char is_unicode; const char is_str; const char intern; } __Pyx_StringTabEntry;

#define __PYX_DEFAULT_STRING_ENCODING_IS_ASCII 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_UTF8 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT (PY_MAJOR_VERSION >= 3 && __PYX_DEFAULT_STRING_ENCODING_IS_UTF8)
#define __PYX_DEFAULT_STRING_ENCODING ""
#define __Pyx_PyObject_FromString __Pyx_PyBytes_FromString
#define __Pyx_PyObject_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#define __Pyx_uchar_cast(c) ((unsigned char)c)
#define __Pyx_long_cast(x) ((long)x)
#define __Pyx_fits_Py_ssize_t(v, type, is_signed)  (\
    (sizeof(type) < sizeof(Py_ssize_t))  ||\
    (sizeof(type) > sizeof(Py_ssize_t) &&\
          likely(v < (type)PY_SSIZE_T_MAX ||\
                 v == (type)PY_SSIZE_T_MAX)  &&\
          (!is_signed || likely(v > (type)PY_SSIZE_T_MIN ||\
                                v == (type)PY_SSIZE_T_MIN)))  ||\
    (sizeof(type) == sizeof(Py_ssize_t) &&\
          (is_signed || likely(v < (type)PY_SSIZE_T_MAX ||\
                               v == (type)PY_SSIZE_T_MAX)))  )
static CYTHON_INLINE int __Pyx_is_valid_index(Py_ssize_t i, Py_ssize_t limit) {
    return (size_t) i < (size_t) limit;
}
#if defined (__cplusplus) && __cplusplus >= 201103L
    #include <cstdlib>
    #define __Pyx_sst_abs(value) std::abs(value)
#elif SIZEOF_INT >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) abs(value)
#elif SIZEOF_LONG >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) labs(value)
#elif defined (_MSC_VER)
    #define __Pyx_sst_abs(value) ((Py_ssize_t)_abs64(value))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define __Pyx_sst_abs(value) llabs(value)
#elif defined (__GNUC__)
    #define __Pyx_sst_abs(value) __builtin_llabs(value)
#else
    #define __Pyx_sst_abs(value) ((value<0) ? -value : value)
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject*);
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject*, Py_ssize_t* length);
#define __Pyx_PyByteArray_FromString(s) PyByteArray_FromStringAndSize((const char*)s, strlen((const char*)s))
#define __Pyx_PyByteArray_FromStringAndSize(s, l) PyByteArray_FromStringAndSize((const char*)s, l)
#define __Pyx_PyBytes_FromString        PyBytes_FromString
#define __Pyx_PyBytes_FromStringAndSize PyBytes_FromStringAndSize
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char*);
#if PY_MAJOR_VERSION < 3
    #define __Pyx_PyStr_FromString        __Pyx_PyBytes_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#else
    #define __Pyx_PyStr_FromString        __Pyx_PyUnicode_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyUnicode_FromStringAndSize
#endif
#define __Pyx_PyBytes_AsWritableString(s)     ((char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableSString(s)    ((signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableUString(s)    ((unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsString(s)     ((const char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsSString(s)    ((const signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsUString(s)    ((const unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyObject_AsWritableString(s)    ((char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableSString(s)    ((signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableUString(s)    ((unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsSString(s)    ((const signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsUString(s)    ((const unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_FromCString(s)  __Pyx_PyObject_FromString((const char*)s)
#define __Pyx_PyBytes_FromCString(s)   __Pyx_PyBytes_FromString((const char*)s)
#define __Pyx_PyByteArray_FromCString(s)   __Pyx_PyByteArray_FromString((const char*)s)
#define __Pyx_PyStr_FromCString(s)     __Pyx_PyStr_FromString((const char*)s)
#define __Pyx_PyUnicode_FromCString(s) __Pyx_PyUnicode_FromString((const char*)s)
static CYTHON_INLINE size_t __Pyx_Py_UNICODE_strlen(const Py_UNICODE *u) {
    const Py_UNICODE *u_end = u;
    while (*u_end++) ;
    return (size_t)(u_end - u - 1);
}
#define __Pyx_PyUnicode_FromUnicode(u)       PyUnicode_FromUnicode(u, __Pyx_Py_UNICODE_strlen(u))
#define __Pyx_PyUnicode_FromUnicodeAndLength PyUnicode_FromUnicode
#define __Pyx_PyUnicode_AsUnicode            PyUnicode_AsUnicode
#define __Pyx_NewRef(obj) (Py_INCREF(obj), obj)
#define __Pyx_Owned_Py_None(b) __Pyx_NewRef(Py_None)
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b);
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject*);
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject*);
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x);
#define __Pyx_PySequence_Tuple(obj)\
    (likely(PyTuple_CheckExact(obj)) ? __Pyx_NewRef(obj) : PySequence_Tuple(obj))
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject*);
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t);
#if CYTHON_ASSUME_SAFE_MACROS
#define __pyx_PyFloat_AsDouble(x) (PyFloat_CheckExact(x) ? PyFloat_AS_DOUBLE(x) : PyFloat_AsDouble(x))
#else
#define __pyx_PyFloat_AsDouble(x) PyFloat_AsDouble(x)
#endif
#define __pyx_PyFloat_AsFloat(x) ((float) __pyx_PyFloat_AsDouble(x))
#if PY_MAJOR_VERSION >= 3
#define __Pyx_PyNumber_Int(x) (PyLong_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Long(x))
#else
#define __Pyx_PyNumber_Int(x) (PyInt_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Int(x))
#endif
#define __Pyx_PyNumber_Float(x) (PyFloat_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Float(x))
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
static int __Pyx_sys_getdefaultencoding_not_ascii;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    PyObject* ascii_chars_u = NULL;
    PyObject* ascii_chars_b = NULL;
    const char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    if (strcmp(default_encoding_c, "ascii") == 0) {
        __Pyx_sys_getdefaultencoding_not_ascii = 0;
    } else {
        char ascii_chars[128];
        int c;
        for (c = 0; c < 128; c++) {
            ascii_chars[c] = c;
        }
        __Pyx_sys_getdefaultencoding_not_ascii = 1;
        ascii_chars_u = PyUnicode_DecodeASCII(ascii_chars, 128, NULL);
        if (!ascii_chars_u) goto bad;
        ascii_chars_b = PyUnicode_AsEncodedString(ascii_chars_u, default_encoding_c, NULL);
        if (!ascii_chars_b || !PyBytes_Check(ascii_chars_b) || memcmp(ascii_chars, PyBytes_AS_STRING(ascii_chars_b), 128) != 0) {
            PyErr_Format(
                PyExc_ValueError,
                "This module compiled with c_string_encoding=ascii, but default encoding '%.200s' is not a superset of ascii.",
                default_encoding_c);
            goto bad;
        }
        Py_DECREF(ascii_chars_u);
        Py_DECREF(ascii_chars_b);
    }
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    Py_XDECREF(ascii_chars_u);
    Py_XDECREF(ascii_chars_b);
    return -1;
}
#endif
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT && PY_MAJOR_VERSION >= 3
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_DecodeUTF8(c_str, size, NULL)
#else
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_Decode(c_str, size, __PYX_DEFAULT_STRING_ENCODING, NULL)
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
static char* __PYX_DEFAULT_STRING_ENCODING;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) (const char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    __PYX_DEFAULT_STRING_ENCODING = (char*) malloc(strlen(default_encoding_c) + 1);
    if (!__PYX_DEFAULT_STRING_ENCODING) goto bad;
    strcpy(__PYX_DEFAULT_STRING_ENCODING, default_encoding_c);
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    return -1;
}
#endif
#endif


/* Test for GCC > 2.95 */
#if defined(__GNUC__)     && (__GNUC__ > 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)))
  #define likely(x)   __builtin_expect(!!(x), 1)
  #define unlikely(x) __builtin_expect(!!(x), 0)
#else /* !__GNUC__ or GCC < 2.95 */
  #define likely(x)   (x)
  #define unlikely(x) (x)
#endif /* __GNUC__ */
static CYTHON_INLINE void __Pyx_pretend_to_initialize(void* ptr) { (void)ptr; }

static PyObject *__pyx_m = NULL;
static PyObject *__pyx_d;
static PyObject *__pyx_b;
static PyObject *__pyx_cython_runtime = NULL;
static PyObject *__pyx_empty_tuple;
static PyObject *__pyx_empty_bytes;
static PyObject *__pyx_empty_unicode;
static int __pyx_lineno;
static int __pyx_clineno = 0;
static const char * __pyx_cfilenm= __FILE__;
static const char *__pyx_filename;


static const char *__pyx_f[] = {
  "cryptz.py",
};

/*--- Type declarations ---*/
struct __pyx_obj_6cryptz___pyx_scope_struct__main;

/* "cryptz.py":59
 *     print(unknown15 + "  made by: " + Red + "Do0pH2ck and inc0gnit0\n" + Reset)
 *     print(unknown15 + "  Instagram: " + Red +"benelhaj_younes(Do0pH2ck) i.nc0gnit0(inc0gnit0)\n" + Reset)
 * def main():             # <<<<<<<<<<<<<<
 *     for i in range(1):
 *         banner()
 */
struct __pyx_obj_6cryptz___pyx_scope_struct__main {
  PyObject_HEAD
  PyObject *__pyx_v_strings;
};


/* --- Runtime support code (head) --- */
/* Refnanny.proto */
#ifndef CYTHON_REFNANNY
  #define CYTHON_REFNANNY 0
#endif
#if CYTHON_REFNANNY
  typedef struct {
    void (*INCREF)(void*, PyObject*, int);
    void (*DECREF)(void*, PyObject*, int);
    void (*GOTREF)(void*, PyObject*, int);
    void (*GIVEREF)(void*, PyObject*, int);
    void* (*SetupContext)(const char*, int, const char*);
    void (*FinishContext)(void**);
  } __Pyx_RefNannyAPIStruct;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNanny = NULL;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname);
  #define __Pyx_RefNannyDeclarations void *__pyx_refnanny = NULL;
#ifdef WITH_THREAD
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          if (acquire_gil) {\
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure();\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
              PyGILState_Release(__pyx_gilstate_save);\
          } else {\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
          }
#else
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__)
#endif
  #define __Pyx_RefNannyFinishContext()\
          __Pyx_RefNanny->FinishContext(&__pyx_refnanny)
  #define __Pyx_INCREF(r)  __Pyx_RefNanny->INCREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_DECREF(r)  __Pyx_RefNanny->DECREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GOTREF(r)  __Pyx_RefNanny->GOTREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GIVEREF(r) __Pyx_RefNanny->GIVEREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_XINCREF(r)  do { if((r) != NULL) {__Pyx_INCREF(r); }} while(0)
  #define __Pyx_XDECREF(r)  do { if((r) != NULL) {__Pyx_DECREF(r); }} while(0)
  #define __Pyx_XGOTREF(r)  do { if((r) != NULL) {__Pyx_GOTREF(r); }} while(0)
  #define __Pyx_XGIVEREF(r) do { if((r) != NULL) {__Pyx_GIVEREF(r);}} while(0)
#else
  #define __Pyx_RefNannyDeclarations
  #define __Pyx_RefNannySetupContext(name, acquire_gil)
  #define __Pyx_RefNannyFinishContext()
  #define __Pyx_INCREF(r) Py_INCREF(r)
  #define __Pyx_DECREF(r) Py_DECREF(r)
  #define __Pyx_GOTREF(r)
  #define __Pyx_GIVEREF(r)
  #define __Pyx_XINCREF(r) Py_XINCREF(r)
  #define __Pyx_XDECREF(r) Py_XDECREF(r)
  #define __Pyx_XGOTREF(r)
  #define __Pyx_XGIVEREF(r)
#endif
#define __Pyx_XDECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_XDECREF(tmp);\
    } while (0)
#define __Pyx_DECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_DECREF(tmp);\
    } while (0)
#define __Pyx_CLEAR(r)    do { PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);} while(0)
#define __Pyx_XCLEAR(r)   do { if((r) != NULL) {PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);}} while(0)

/* PyObjectGetAttrStr.proto */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GetAttrStr(o,n) PyObject_GetAttr(o,n)
#endif

/* GetBuiltinName.proto */
static PyObject *__Pyx_GetBuiltinName(PyObject *name);

/* PyDictVersioning.proto */
#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
#define __PYX_DICT_VERSION_INIT  ((PY_UINT64_T) -1)
#define __PYX_GET_DICT_VERSION(dict)  (((PyDictObject*)(dict))->ma_version_tag)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)\
    (version_var) = __PYX_GET_DICT_VERSION(dict);\
    (cache_var) = (value);
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP) {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    if (likely(__PYX_GET_DICT_VERSION(DICT) == __pyx_dict_version)) {\
        (VAR) = __pyx_dict_cached_value;\
    } else {\
        (VAR) = __pyx_dict_cached_value = (LOOKUP);\
        __pyx_dict_version = __PYX_GET_DICT_VERSION(DICT);\
    }\
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj);
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj);
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version);
#else
#define __PYX_GET_DICT_VERSION(dict)  (0)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP)  (VAR) = (LOOKUP);
#endif

/* GetModuleGlobalName.proto */
#if CYTHON_USE_DICT_VERSIONS
#define __Pyx_GetModuleGlobalName(var, name)  {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    (var) = (likely(__pyx_dict_version == __PYX_GET_DICT_VERSION(__pyx_d))) ?\
        (likely(__pyx_dict_cached_value) ? __Pyx_NewRef(__pyx_dict_cached_value) : __Pyx_GetBuiltinName(name)) :\
        __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
#define __Pyx_GetModuleGlobalNameUncached(var, name)  {\
    PY_UINT64_T __pyx_dict_version;\
    PyObject *__pyx_dict_cached_value;\
    (var) = __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value);
#else
#define __Pyx_GetModuleGlobalName(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
#define __Pyx_GetModuleGlobalNameUncached(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name);
#endif

/* PyCFunctionFastCall.proto */
#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject *__Pyx_PyCFunction_FastCall(PyObject *func, PyObject **args, Py_ssize_t nargs);
#else
#define __Pyx_PyCFunction_FastCall(func, args, nargs)  (assert(0), NULL)
#endif

/* PyFunctionFastCall.proto */
#if CYTHON_FAST_PYCALL
#define __Pyx_PyFunction_FastCall(func, args, nargs)\
    __Pyx_PyFunction_FastCallDict((func), (args), (nargs), NULL)
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs);
#else
#define __Pyx_PyFunction_FastCallDict(func, args, nargs, kwargs) _PyFunction_FastCallDict(func, args, nargs, kwargs)
#endif
#define __Pyx_BUILD_ASSERT_EXPR(cond)\
    (sizeof(char [1 - 2*!(cond)]) - 1)
#ifndef Py_MEMBER_SIZE
#define Py_MEMBER_SIZE(type, member) sizeof(((type *)0)->member)
#endif
  static size_t __pyx_pyframe_localsplus_offset = 0;
  #include "frameobject.h"
  #define __Pxy_PyFrame_Initialize_Offsets()\
    ((void)__Pyx_BUILD_ASSERT_EXPR(sizeof(PyFrameObject) == offsetof(PyFrameObject, f_localsplus) + Py_MEMBER_SIZE(PyFrameObject, f_localsplus)),\
     (void)(__pyx_pyframe_localsplus_offset = ((size_t)PyFrame_Type.tp_basicsize) - Py_MEMBER_SIZE(PyFrameObject, f_localsplus)))
  #define __Pyx_PyFrame_GetLocalsplus(frame)\
    (assert(__pyx_pyframe_localsplus_offset), (PyObject **)(((char *)(frame)) + __pyx_pyframe_localsplus_offset))
#endif

/* PyObjectCall.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw);
#else
#define __Pyx_PyObject_Call(func, arg, kw) PyObject_Call(func, arg, kw)
#endif

/* PyObjectCall2Args.proto */
static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2);

/* PyObjectCallMethO.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg);
#endif

/* PyObjectCallOneArg.proto */
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg);

/* GetItemInt.proto */
#define __Pyx_GetItemInt(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Fast(o, (Py_ssize_t)i, is_list, wraparound, boundscheck) :\
    (is_list ? (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL) :\
               __Pyx_GetItemInt_Generic(o, to_py_func(i))))
#define __Pyx_GetItemInt_List(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_List_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
#define __Pyx_GetItemInt_Tuple(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Tuple_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "tuple index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j);
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i,
                                                     int is_list, int wraparound, int boundscheck);

/* ObjectGetItem.proto */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject *__Pyx_PyObject_GetItem(PyObject *obj, PyObject* key);
#else
#define __Pyx_PyObject_GetItem(obj, key)  PyObject_GetItem(obj, key)
#endif

/* SliceObject.proto */
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetSlice(
        PyObject* obj, Py_ssize_t cstart, Py_ssize_t cstop,
        PyObject** py_start, PyObject** py_stop, PyObject** py_slice,
        int has_cstart, int has_cstop, int wraparound);

/* None.proto */
static CYTHON_INLINE void __Pyx_RaiseClosureNameError(const char *varname);

/* RaiseArgTupleInvalid.proto */
static void __Pyx_RaiseArgtupleInvalid(const char* func_name, int exact,
    Py_ssize_t num_min, Py_ssize_t num_max, Py_ssize_t num_found);

/* RaiseDoubleKeywords.proto */
static void __Pyx_RaiseDoubleKeywordsError(const char* func_name, PyObject* kw_name);

/* ParseKeywords.proto */
static int __Pyx_ParseOptionalKeywords(PyObject *kwds, PyObject **argnames[],\
    PyObject *kwds2, PyObject *values[], Py_ssize_t num_pos_args,\
    const char* function_name);

/* PyObjectCallNoArg.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func);
#else
#define __Pyx_PyObject_CallNoArg(func) __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL)
#endif

/* PyObjectLookupSpecial.proto */
#if CYTHON_USE_PYTYPE_LOOKUP && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_LookupSpecial(PyObject* obj, PyObject* attr_name) {
    PyObject *res;
    PyTypeObject *tp = Py_TYPE(obj);
#if PY_MAJOR_VERSION < 3
    if (unlikely(PyInstance_Check(obj)))
        return __Pyx_PyObject_GetAttrStr(obj, attr_name);
#endif
    res = _PyType_Lookup(tp, attr_name);
    if (likely(res)) {
        descrgetfunc f = Py_TYPE(res)->tp_descr_get;
        if (!f) {
            Py_INCREF(res);
        } else {
            res = f(res, obj, (PyObject *)tp);
        }
    } else {
        PyErr_SetObject(PyExc_AttributeError, attr_name);
    }
    return res;
}
#else
#define __Pyx_PyObject_LookupSpecial(o,n) __Pyx_PyObject_GetAttrStr(o,n)
#endif

/* GetTopmostException.proto */
#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem * __Pyx_PyErr_GetTopmostException(PyThreadState *tstate);
#endif

/* PyThreadStateGet.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyThreadState_declare  PyThreadState *__pyx_tstate;
#define __Pyx_PyThreadState_assign  __pyx_tstate = __Pyx_PyThreadState_Current;
#define __Pyx_PyErr_Occurred()  __pyx_tstate->curexc_type
#else
#define __Pyx_PyThreadState_declare
#define __Pyx_PyThreadState_assign
#define __Pyx_PyErr_Occurred()  PyErr_Occurred()
#endif

/* SaveResetException.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSave(type, value, tb)  __Pyx__ExceptionSave(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#define __Pyx_ExceptionReset(type, value, tb)  __Pyx__ExceptionReset(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
#else
#define __Pyx_ExceptionSave(type, value, tb)   PyErr_GetExcInfo(type, value, tb)
#define __Pyx_ExceptionReset(type, value, tb)  PyErr_SetExcInfo(type, value, tb)
#endif

/* GetException.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_GetException(type, value, tb)  __Pyx__GetException(__pyx_tstate, type, value, tb)
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb);
#endif

/* PyErrFetchRestore.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_Clear() __Pyx_ErrRestore(NULL, NULL, NULL)
#define __Pyx_ErrRestoreWithState(type, value, tb)  __Pyx_ErrRestoreInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)    __Pyx_ErrFetchInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  __Pyx_ErrRestoreInState(__pyx_tstate, type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)    __Pyx_ErrFetchInState(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_PyErr_SetNone(exc) (Py_INCREF(exc), __Pyx_ErrRestore((exc), NULL, NULL))
#else
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#endif
#else
#define __Pyx_PyErr_Clear() PyErr_Clear()
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#define __Pyx_ErrRestoreWithState(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestoreInState(tstate, type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchInState(tstate, type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)  PyErr_Fetch(type, value, tb)
#endif

/* None.proto */
static CYTHON_INLINE void __Pyx_RaiseUnboundLocalError(const char *varname);

/* FetchCommonType.proto */
static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type);

/* CythonFunction.proto */
#define __Pyx_CyFunction_USED 1
#define __Pyx_CYFUNCTION_STATICMETHOD  0x01
#define __Pyx_CYFUNCTION_CLASSMETHOD   0x02
#define __Pyx_CYFUNCTION_CCLASS        0x04
#define __Pyx_CyFunction_GetClosure(f)\
    (((__pyx_CyFunctionObject *) (f))->func_closure)
#define __Pyx_CyFunction_GetClassObj(f)\
    (((__pyx_CyFunctionObject *) (f))->func_classobj)
#define __Pyx_CyFunction_Defaults(type, f)\
    ((type *)(((__pyx_CyFunctionObject *) (f))->defaults))
#define __Pyx_CyFunction_SetDefaultsGetter(f, g)\
    ((__pyx_CyFunctionObject *) (f))->defaults_getter = (g)
typedef struct {
    PyCFunctionObject func;
#if PY_VERSION_HEX < 0x030500A0
    PyObject *func_weakreflist;
#endif
    PyObject *func_dict;
    PyObject *func_name;
    PyObject *func_qualname;
    PyObject *func_doc;
    PyObject *func_globals;
    PyObject *func_code;
    PyObject *func_closure;
    PyObject *func_classobj;
    void *defaults;
    int defaults_pyobjects;
    int flags;
    PyObject *defaults_tuple;
    PyObject *defaults_kwdict;
    PyObject *(*defaults_getter)(PyObject *);
    PyObject *func_annotations;
} __pyx_CyFunctionObject;
static PyTypeObject *__pyx_CyFunctionType = 0;
#define __Pyx_CyFunction_Check(obj)  (__Pyx_TypeCheck(obj, __pyx_CyFunctionType))
#define __Pyx_CyFunction_NewEx(ml, flags, qualname, self, module, globals, code)\
    __Pyx_CyFunction_New(__pyx_CyFunctionType, ml, flags, qualname, self, module, globals, code)
static PyObject *__Pyx_CyFunction_New(PyTypeObject *, PyMethodDef *ml,
                                      int flags, PyObject* qualname,
                                      PyObject *self,
                                      PyObject *module, PyObject *globals,
                                      PyObject* code);
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *m,
                                                         size_t size,
                                                         int pyobjects);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *m,
                                                            PyObject *tuple);
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *m,
                                                             PyObject *dict);
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *m,
                                                              PyObject *dict);
static int __pyx_CyFunction_init(void);

/* IncludeStringH.proto */
#include <string.h>

/* BytesEquals.proto */
static CYTHON_INLINE int __Pyx_PyBytes_Equals(PyObject* s1, PyObject* s2, int equals);

/* UnicodeEquals.proto */
static CYTHON_INLINE int __Pyx_PyUnicode_Equals(PyObject* s1, PyObject* s2, int equals);

/* PyObject_GenericGetAttrNoDict.proto */
#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static CYTHON_INLINE PyObject* __Pyx_PyObject_GenericGetAttrNoDict(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GenericGetAttrNoDict PyObject_GenericGetAttr
#endif

/* Import.proto */
static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level);

/* ImportFrom.proto */
static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name);

/* PyErrExceptionMatches.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_ExceptionMatches(err) __Pyx_PyErr_ExceptionMatchesInState(__pyx_tstate, err)
static CYTHON_INLINE int __Pyx_PyErr_ExceptionMatchesInState(PyThreadState* tstate, PyObject* err);
#else
#define __Pyx_PyErr_ExceptionMatches(err)  PyErr_ExceptionMatches(err)
#endif

/* CLineInTraceback.proto */
#ifdef CYTHON_CLINE_IN_TRACEBACK
#define __Pyx_CLineForTraceback(tstate, c_line)  (((CYTHON_CLINE_IN_TRACEBACK)) ? c_line : 0)
#else
static int __Pyx_CLineForTraceback(PyThreadState *tstate, int c_line);
#endif

/* CodeObjectCache.proto */
typedef struct {
    PyCodeObject* code_object;
    int code_line;
} __Pyx_CodeObjectCacheEntry;
struct __Pyx_CodeObjectCache {
    int count;
    int max_count;
    __Pyx_CodeObjectCacheEntry* entries;
};
static struct __Pyx_CodeObjectCache __pyx_code_cache = {0,0,NULL};
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line);
static PyCodeObject *__pyx_find_code_object(int code_line);
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object);

/* AddTraceback.proto */
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename);

/* CIntToPy.proto */
static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value);

/* CIntFromPy.proto */
static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *);

/* CIntFromPy.proto */
static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *);

/* FastTypeChecks.proto */
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_TypeCheck(obj, type) __Pyx_IsSubtype(Py_TYPE(obj), (PyTypeObject *)type)
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject *type);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *type1, PyObject *type2);
#else
#define __Pyx_TypeCheck(obj, type) PyObject_TypeCheck(obj, (PyTypeObject *)type)
#define __Pyx_PyErr_GivenExceptionMatches(err, type) PyErr_GivenExceptionMatches(err, type)
#define __Pyx_PyErr_GivenExceptionMatches2(err, type1, type2) (PyErr_GivenExceptionMatches(err, type1) || PyErr_GivenExceptionMatches(err, type2))
#endif
#define __Pyx_PyException_Check(obj) __Pyx_TypeCheck(obj, PyExc_Exception)

/* CheckBinaryVersion.proto */
static int __Pyx_check_binary_version(void);

/* InitStrings.proto */
static int __Pyx_InitStrings(__Pyx_StringTabEntry *t);


/* Module declarations from 'cryptz' */
static PyTypeObject *__pyx_ptype_6cryptz___pyx_scope_struct__main = 0;
#define __Pyx_MODULE_NAME "cryptz"
extern int __pyx_module_is_main_cryptz;
int __pyx_module_is_main_cryptz = 0;

/* Implementation of 'cryptz' */
static PyObject *__pyx_builtin_ImportError;
static PyObject *__pyx_builtin_print;
static PyObject *__pyx_builtin_exit;
static PyObject *__pyx_builtin_range;
static PyObject *__pyx_builtin_input;
static const char __pyx_k_[] = "   ####   #####   #   #  #####   #####  ###### ";
static const char __pyx_k_D[] = "D";
static const char __pyx_k_E[] = "E";
static const char __pyx_k_c[] = "c";
static const char __pyx_k_d[] = "d";
static const char __pyx_k_e[] = "e";
static const char __pyx_k_i[] = "i";
static const char __pyx_k_s[] = "s";
static const char __pyx_k_0m[] = "\033[0m \n";
static const char __pyx_k__2[] = "  #    #  #    #   # #   #    #    #        # ";
static const char __pyx_k__3[] = "  #       #    #    #    #    #    #       # ";
static const char __pyx_k__4[] = "  #       #####     #    #####     #      # ";
static const char __pyx_k__5[] = "  #    #  #   #     #    #         #     # ";
static const char __pyx_k__9[] = "";
static const char __pyx_k_db[] = "db";
static const char __pyx_k_os[] = "os";
static const char __pyx_k_re[] = "re";
static const char __pyx_k_sl[] = "sl";
static const char __pyx_k_31m[] = "   ####   #    #    #    #         #    ######  \033[31m";
static const char __pyx_k_35m[] = "\033[35m";
static const char __pyx_k_39m[] = "\033[39m";
static const char __pyx_k_95m[] = "\033[95m";
static const char __pyx_k_96m[] = "\033[96m";
static const char __pyx_k_Red[] = "Red";
static const char __pyx_k__31[] = "\n";
static const char __pyx_k__38[] = "{}:{}:{}";
static const char __pyx_k_dec[] = "dec";
static const char __pyx_k_min[] = "min";
static const char __pyx_k_now[] = "now";
static const char __pyx_k_sec[] = "sec";
static const char __pyx_k_sys[] = "sys";
static const char __pyx_k_0m_2[] = "\033[0m";
static const char __pyx_k_Blue[] = "Blue";
static const char __pyx_k_Grey[] = "Grey";
static const char __pyx_k_char[] = "char";
static const char __pyx_k_cyan[] = "cyan";
static const char __pyx_k_data[] = "data";
static const char __pyx_k_exit[] = "exit";
static const char __pyx_k_hour[] = "hour";
static const char __pyx_k_main[] = "__main__";
static const char __pyx_k_name[] = "__name__";
static const char __pyx_k_test[] = "__test__";
static const char __pyx_k_text[] = "text";
static const char __pyx_k_time[] = "time";
static const char __pyx_k_v3_0[] = "v3.0";
static const char __pyx_k_1_30m[] = "\033[1;30m";
static const char __pyx_k_1_31m[] = "\033[1;31m";
static const char __pyx_k_1_33m[] = "\033[1;33m";
static const char __pyx_k_1_34m[] = "\033[1;34m";
static const char __pyx_k_1_36m[] = "\033[1;36m";
static const char __pyx_k_Green[] = "Green";
static const char __pyx_k_Light[] = "Light";
static const char __pyx_k_Reset[] = "Reset";
static const char __pyx_k_clear[] = "clear";
static const char __pyx_k_enter[] = "__enter__";
static const char __pyx_k_input[] = "input";
static const char __pyx_k_print[] = "print";
static const char __pyx_k_range[] = "range";
static const char __pyx_k_resul[] = "resul";
static const char __pyx_k_sleep[] = "sleep";
static const char __pyx_k_stong[] = "stong";
static const char __pyx_k_banner[] = "banner";
static const char __pyx_k_choice[] = "choice";
static const char __pyx_k_cryptz[] = "cryptz";
static const char __pyx_k_cursor[] = "cursor";
static const char __pyx_k_decode[] = "decode";
static const char __pyx_k_encode[] = "encode";
static const char __pyx_k_exit_2[] = "__exit__";
static const char __pyx_k_format[] = "format";
static const char __pyx_k_import[] = "__import__";
static const char __pyx_k_main_2[] = "main";
static const char __pyx_k_minute[] = "minute";
static const char __pyx_k_purple[] = "purple";
static const char __pyx_k_result[] = "result";
static const char __pyx_k_second[] = "second";
static const char __pyx_k_system[] = "system";
static const char __pyx_k_yellow[] = "yellow";
static const char __pyx_k_E_D_e_d[] = " [E/D,e/d]: ";
static const char __pyx_k_connect[] = "connect";
static const char __pyx_k_encode1[] = "encode1";
static const char __pyx_k_execute[] = "execute";
static const char __pyx_k_made_by[] = "  made by: ";
static const char __pyx_k_replace[] = "replace";
static const char __pyx_k_sqlite3[] = "sqlite3";
static const char __pyx_k_strings[] = "strings";
static const char __pyx_k_timenow[] = "timenow";
static const char __pyx_k_unknown[] = "unknown";
static const char __pyx_k_38_5_13m[] = "\033[38;5;13m";
static const char __pyx_k_38_5_14m[] = "\033[38;5;14m";
static const char __pyx_k_38_5_49m[] = "\033[38;5;49m";
static const char __pyx_k_38_5_51m[] = "\033[38;5;51m";
static const char __pyx_k_38_5_82m[] = "\033[38;5;82m";
static const char __pyx_k_38_5_91m[] = "\033[38;5;91m";
static const char __pyx_k_connect1[] = "connect1";
static const char __pyx_k_datetime[] = "datetime";
static const char __pyx_k_fetchall[] = "fetchall";
static const char __pyx_k_password[] = "password";
static const char __pyx_k_pybase64[] = "pybase64";
static const char __pyx_k_store_db[] = "store.db";
static const char __pyx_k_unknown2[] = "unknown2";
static const char __pyx_k_unknown3[] = "unknown3";
static const char __pyx_k_unknown4[] = "unknown4";
static const char __pyx_k_unknown5[] = "unknown5";
static const char __pyx_k_unknown6[] = "unknown6";
static const char __pyx_k_unknown7[] = "unknown7";
static const char __pyx_k_unknown8[] = "unknown8";
static const char __pyx_k_unknown9[] = "unknown9";
static const char __pyx_k_38_5_113m[] = "\033[38;5;113m";
static const char __pyx_k_38_5_160m[] = "\033[38;5;160m";
static const char __pyx_k_38_5_162m[] = "\033[38;5;162m";
static const char __pyx_k_38_5_165m[] = "\033[38;5;165m";
static const char __pyx_k_38_5_167m[] = "\033[38;5;167m";
static const char __pyx_k_38_5_198m[] = "\033[38;5;198m";
static const char __pyx_k_38_5_203m[] = "\033[38;5;203m";
static const char __pyx_k_38_5_208m[] = "\033[38;5;208m";
static const char __pyx_k_38_5_210m[] = "\033[38;5;210m";
static const char __pyx_k_Instagram[] = "  Instagram: ";
static const char __pyx_k_b64decode[] = "b64decode";
static const char __pyx_k_b64encode[] = "b64encode";
static const char __pyx_k_clear_cls[] = "clear || cls";
static const char __pyx_k_cryptz_py[] = "cryptz.py";
static const char __pyx_k_unknown10[] = "unknown10";
static const char __pyx_k_unknown11[] = "unknown11";
static const char __pyx_k_unknown12[] = "unknown12";
static const char __pyx_k_unknown13[] = "unknown13";
static const char __pyx_k_unknown14[] = "unknown14";
static const char __pyx_k_unknown15[] = "unknown15";
static const char __pyx_k_Started_At[] = "  Started At {}";
static const char __pyx_k_add_string[] = "add_string";
static const char __pyx_k_catch_pass[] = "catch_pass";
static const char __pyx_k_pybase64_2[] = "_pybase64";
static const char __pyx_k_rem_string[] = "rem_string";
static const char __pyx_k_ImportError[] = "ImportError";
static const char __pyx_k_reverse_char[] = "reverse_char";
static const char __pyx_k_Access_Granted[] = "\n  Access Granted!!!";
static const char __pyx_k_unreversed_char[] = "unreversed_char";
static const char __pyx_k_Enter_License_Key[] = "  Enter License Key: ";
static const char __pyx_k_CRYPTZ_is_starting[] = "  CRYPTZ is starting!!";
static const char __pyx_k_cline_in_traceback[] = "cline_in_traceback";
static const char __pyx_k_Loading_Resources_0[] = "  Loading Resources...[0%]";
static const char __pyx_k_Loading_Resources_10[] = "  Loading Resources...[10%]";
static const char __pyx_k_Loading_Resources_20[] = "  Loading Resources...[20%]";
static const char __pyx_k_Loading_Resources_30[] = "  Loading Resources...[30%]";
static const char __pyx_k_Loading_Resources_40[] = "  Loading Resources...[40%]";
static const char __pyx_k_Loading_Resources_50[] = "  Loading Resources...[50%]";
static const char __pyx_k_Loading_Resources_60[] = "  Loading Resources...[60%]";
static const char __pyx_k_Loading_Resources_70[] = "  Loading Resources...[70%]";
static const char __pyx_k_Loading_Resources_80[] = "  Loading Resources...[80%]";
static const char __pyx_k_Loading_Resources_90[] = "  Loading Resources...[90%]";
static const char __pyx_k_Do0pH2ck_and_inc0gnit0[] = "Do0pH2ck and inc0gnit0\n";
static const char __pyx_k_main_locals_add_string[] = "main.<locals>.add_string";
static const char __pyx_k_main_locals_rem_string[] = "main.<locals>.rem_string";
static const char __pyx_k_main_locals_reverse_char[] = "main.<locals>.reverse_char";
static const char __pyx_k_Thank_You_for_Using_CRYPTZ[] = "\nThank You for Using CRYPTZ";
static const char __pyx_k_main_locals_unreversed_char[] = "main.<locals>.unreversed_char";
static const char __pyx_k_Enter_Your_Encrypted_Message[] = "Enter Your Encrypted Message: ";
static const char __pyx_k_Enter_Your_Plain_Text_Message[] = "  Enter Your Plain Text Message: ";
static const char __pyx_k_31mPlease_run_python3_install_p[] = "\033[31mPlease run: python3 install.py\033[0m";
static const char __pyx_k_Do_You_Want_To_Encrypt_Or_Decry[] = "  Do You Want To Encrypt Or Decrypt";
static const char __pyx_k_Loading_Resources_1000000000000[] = "  Loading Resources...[1000000000000%]";
static const char __pyx_k_Unauthorized_Access_Warning_Don[] = "  Unauthorized Access !!\n  Warning Don't Try Random Things Or You'll Be Banned!!\n  To get a License Key you will need to contact creators for one";
static const char __pyx_k_Unknown_Option_Quiting_Don_t_fo[] = "  Unknown Option Quiting...\n  Don't forget to follow us on Instagram!!\n";
static const char __pyx_k_Welcome_To_CRYPTZ_The_Unbreakab[] = "\n                Welcome To CRYPTZ The Unbreakable Tool\n                ";
static const char __pyx_k_https_github_com_doophack_crypt[] = "\n  https://github.com/doophack/cryptz\n";
static const char __pyx_k_1h3sgj5ks3erhg3h5dh23455wer32cfe[] = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf";
static const char __pyx_k_SELECT_FROM_passman_WHERE_licens[] = "SELECT * FROM passman WHERE licensekey = ?";
static const char __pyx_k_benelhaj_younes_Do0pH2ck_i_nc0gn[] = "benelhaj_younes(Do0pH2ck) i.nc0gnit0(inc0gnit0)\n";
static PyObject *__pyx_kp_u_;
static PyObject *__pyx_kp_u_0m;
static PyObject *__pyx_kp_u_0m_2;
static PyObject *__pyx_kp_u_1_30m;
static PyObject *__pyx_kp_u_1_31m;
static PyObject *__pyx_kp_u_1_33m;
static PyObject *__pyx_kp_u_1_34m;
static PyObject *__pyx_kp_u_1_36m;
static PyObject *__pyx_kp_u_1h3sgj5ks3erhg3h5dh23455wer32cfe;
static PyObject *__pyx_kp_u_31m;
static PyObject *__pyx_kp_u_31mPlease_run_python3_install_p;
static PyObject *__pyx_kp_u_35m;
static PyObject *__pyx_kp_u_38_5_113m;
static PyObject *__pyx_kp_u_38_5_13m;
static PyObject *__pyx_kp_u_38_5_14m;
static PyObject *__pyx_kp_u_38_5_160m;
static PyObject *__pyx_kp_u_38_5_162m;
static PyObject *__pyx_kp_u_38_5_165m;
static PyObject *__pyx_kp_u_38_5_167m;
static PyObject *__pyx_kp_u_38_5_198m;
static PyObject *__pyx_kp_u_38_5_203m;
static PyObject *__pyx_kp_u_38_5_208m;
static PyObject *__pyx_kp_u_38_5_210m;
static PyObject *__pyx_kp_u_38_5_49m;
static PyObject *__pyx_kp_u_38_5_51m;
static PyObject *__pyx_kp_u_38_5_82m;
static PyObject *__pyx_kp_u_38_5_91m;
static PyObject *__pyx_kp_u_39m;
static PyObject *__pyx_kp_u_95m;
static PyObject *__pyx_kp_u_96m;
static PyObject *__pyx_kp_u_Access_Granted;
static PyObject *__pyx_n_s_Blue;
static PyObject *__pyx_kp_u_CRYPTZ_is_starting;
static PyObject *__pyx_n_u_D;
static PyObject *__pyx_kp_u_Do0pH2ck_and_inc0gnit0;
static PyObject *__pyx_kp_u_Do_You_Want_To_Encrypt_Or_Decry;
static PyObject *__pyx_n_u_E;
static PyObject *__pyx_kp_u_E_D_e_d;
static PyObject *__pyx_kp_u_Enter_License_Key;
static PyObject *__pyx_kp_u_Enter_Your_Encrypted_Message;
static PyObject *__pyx_kp_u_Enter_Your_Plain_Text_Message;
static PyObject *__pyx_n_s_Green;
static PyObject *__pyx_n_s_Grey;
static PyObject *__pyx_n_s_ImportError;
static PyObject *__pyx_kp_u_Instagram;
static PyObject *__pyx_n_s_Light;
static PyObject *__pyx_kp_u_Loading_Resources_0;
static PyObject *__pyx_kp_u_Loading_Resources_10;
static PyObject *__pyx_kp_u_Loading_Resources_1000000000000;
static PyObject *__pyx_kp_u_Loading_Resources_20;
static PyObject *__pyx_kp_u_Loading_Resources_30;
static PyObject *__pyx_kp_u_Loading_Resources_40;
static PyObject *__pyx_kp_u_Loading_Resources_50;
static PyObject *__pyx_kp_u_Loading_Resources_60;
static PyObject *__pyx_kp_u_Loading_Resources_70;
static PyObject *__pyx_kp_u_Loading_Resources_80;
static PyObject *__pyx_kp_u_Loading_Resources_90;
static PyObject *__pyx_n_s_Red;
static PyObject *__pyx_n_s_Reset;
static PyObject *__pyx_kp_u_SELECT_FROM_passman_WHERE_licens;
static PyObject *__pyx_kp_u_Started_At;
static PyObject *__pyx_kp_u_Thank_You_for_Using_CRYPTZ;
static PyObject *__pyx_kp_u_Unauthorized_Access_Warning_Don;
static PyObject *__pyx_kp_u_Unknown_Option_Quiting_Don_t_fo;
static PyObject *__pyx_kp_u_Welcome_To_CRYPTZ_The_Unbreakab;
static PyObject *__pyx_kp_u__2;
static PyObject *__pyx_kp_u__3;
static PyObject *__pyx_kp_u__31;
static PyObject *__pyx_kp_u__38;
static PyObject *__pyx_kp_u__4;
static PyObject *__pyx_kp_u__5;
static PyObject *__pyx_kp_u__9;
static PyObject *__pyx_n_s_add_string;
static PyObject *__pyx_n_s_b64decode;
static PyObject *__pyx_n_s_b64encode;
static PyObject *__pyx_n_s_banner;
static PyObject *__pyx_kp_u_benelhaj_younes_Do0pH2ck_i_nc0gn;
static PyObject *__pyx_n_s_c;
static PyObject *__pyx_n_s_catch_pass;
static PyObject *__pyx_n_s_char;
static PyObject *__pyx_n_s_choice;
static PyObject *__pyx_n_s_clear;
static PyObject *__pyx_kp_u_clear_cls;
static PyObject *__pyx_n_s_cline_in_traceback;
static PyObject *__pyx_n_s_connect;
static PyObject *__pyx_n_s_connect1;
static PyObject *__pyx_n_s_cryptz;
static PyObject *__pyx_kp_s_cryptz_py;
static PyObject *__pyx_n_s_cursor;
static PyObject *__pyx_n_s_cyan;
static PyObject *__pyx_n_u_d;
static PyObject *__pyx_n_s_data;
static PyObject *__pyx_n_s_datetime;
static PyObject *__pyx_n_s_db;
static PyObject *__pyx_n_s_dec;
static PyObject *__pyx_n_s_decode;
static PyObject *__pyx_n_u_e;
static PyObject *__pyx_n_s_encode;
static PyObject *__pyx_n_s_encode1;
static PyObject *__pyx_n_s_enter;
static PyObject *__pyx_n_s_execute;
static PyObject *__pyx_n_s_exit;
static PyObject *__pyx_n_s_exit_2;
static PyObject *__pyx_n_s_fetchall;
static PyObject *__pyx_n_s_format;
static PyObject *__pyx_n_s_hour;
static PyObject *__pyx_kp_u_https_github_com_doophack_crypt;
static PyObject *__pyx_n_s_i;
static PyObject *__pyx_n_s_import;
static PyObject *__pyx_n_s_input;
static PyObject *__pyx_kp_u_made_by;
static PyObject *__pyx_n_s_main;
static PyObject *__pyx_n_u_main;
static PyObject *__pyx_n_s_main_2;
static PyObject *__pyx_n_s_main_locals_add_string;
static PyObject *__pyx_n_s_main_locals_rem_string;
static PyObject *__pyx_n_s_main_locals_reverse_char;
static PyObject *__pyx_n_s_main_locals_unreversed_char;
static PyObject *__pyx_n_s_min;
static PyObject *__pyx_n_s_minute;
static PyObject *__pyx_n_s_name;
static PyObject *__pyx_n_s_now;
static PyObject *__pyx_n_s_os;
static PyObject *__pyx_n_s_password;
static PyObject *__pyx_n_s_print;
static PyObject *__pyx_n_s_purple;
static PyObject *__pyx_n_s_pybase64;
static PyObject *__pyx_n_s_pybase64_2;
static PyObject *__pyx_n_s_range;
static PyObject *__pyx_n_s_re;
static PyObject *__pyx_n_s_rem_string;
static PyObject *__pyx_n_s_replace;
static PyObject *__pyx_n_s_resul;
static PyObject *__pyx_n_s_result;
static PyObject *__pyx_n_s_reverse_char;
static PyObject *__pyx_n_s_s;
static PyObject *__pyx_n_s_sec;
static PyObject *__pyx_n_s_second;
static PyObject *__pyx_n_s_sl;
static PyObject *__pyx_n_s_sleep;
static PyObject *__pyx_n_s_sqlite3;
static PyObject *__pyx_n_s_stong;
static PyObject *__pyx_kp_u_store_db;
static PyObject *__pyx_n_s_strings;
static PyObject *__pyx_n_s_sys;
static PyObject *__pyx_n_s_system;
static PyObject *__pyx_n_s_test;
static PyObject *__pyx_n_s_text;
static PyObject *__pyx_n_s_time;
static PyObject *__pyx_n_s_timenow;
static PyObject *__pyx_n_s_unknown;
static PyObject *__pyx_n_s_unknown10;
static PyObject *__pyx_n_s_unknown11;
static PyObject *__pyx_n_s_unknown12;
static PyObject *__pyx_n_s_unknown13;
static PyObject *__pyx_n_s_unknown14;
static PyObject *__pyx_n_s_unknown15;
static PyObject *__pyx_n_s_unknown2;
static PyObject *__pyx_n_s_unknown3;
static PyObject *__pyx_n_s_unknown4;
static PyObject *__pyx_n_s_unknown5;
static PyObject *__pyx_n_s_unknown6;
static PyObject *__pyx_n_s_unknown7;
static PyObject *__pyx_n_s_unknown8;
static PyObject *__pyx_n_s_unknown9;
static PyObject *__pyx_n_s_unreversed_char;
static PyObject *__pyx_kp_u_v3_0;
static PyObject *__pyx_n_s_yellow;
static PyObject *__pyx_pf_6cryptz_clear(CYTHON_UNUSED PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_6cryptz_2banner(CYTHON_UNUSED PyObject *__pyx_self); /* proto */
static PyObject *__pyx_pf_6cryptz_4main_reverse_char(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_s); /* proto */
static PyObject *__pyx_pf_6cryptz_4main_2unreversed_char(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_s); /* proto */
static PyObject *__pyx_pf_6cryptz_4main_4add_string(PyObject *__pyx_self, PyObject *__pyx_v_s); /* proto */
static PyObject *__pyx_pf_6cryptz_4main_6rem_string(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_text, PyObject *__pyx_v_char); /* proto */
static PyObject *__pyx_pf_6cryptz_4main(CYTHON_UNUSED PyObject *__pyx_self); /* proto */
static PyObject *__pyx_tp_new_6cryptz___pyx_scope_struct__main(PyTypeObject *t, PyObject *a, PyObject *k); /*proto*/
static PyObject *__pyx_float_0_10;
static PyObject *__pyx_int_1;
static PyObject *__pyx_int_3;
static PyObject *__pyx_int_5;
static PyObject *__pyx_int_neg_1;
static PyObject *__pyx_slice__6;
static PyObject *__pyx_slice__7;
static PyObject *__pyx_slice__8;
static PyObject *__pyx_tuple__10;
static PyObject *__pyx_tuple__11;
static PyObject *__pyx_tuple__12;
static PyObject *__pyx_tuple__13;
static PyObject *__pyx_tuple__14;
static PyObject *__pyx_tuple__15;
static PyObject *__pyx_tuple__16;
static PyObject *__pyx_tuple__17;
static PyObject *__pyx_tuple__18;
static PyObject *__pyx_tuple__19;
static PyObject *__pyx_tuple__20;
static PyObject *__pyx_tuple__21;
static PyObject *__pyx_tuple__22;
static PyObject *__pyx_tuple__23;
static PyObject *__pyx_tuple__25;
static PyObject *__pyx_tuple__27;
static PyObject *__pyx_tuple__29;
static PyObject *__pyx_tuple__32;
static PyObject *__pyx_tuple__33;
static PyObject *__pyx_tuple__34;
static PyObject *__pyx_tuple__35;
static PyObject *__pyx_tuple__36;
static PyObject *__pyx_tuple__40;
static PyObject *__pyx_codeobj__24;
static PyObject *__pyx_codeobj__26;
static PyObject *__pyx_codeobj__28;
static PyObject *__pyx_codeobj__30;
static PyObject *__pyx_codeobj__37;
static PyObject *__pyx_codeobj__39;
static PyObject *__pyx_codeobj__41;
/* Late includes */

/* "cryptz.py":12
 *         print("\033[31m" + "Please run: python3 install.py" + "\033[0m")
 *         exit(1)
 * def clear():             # <<<<<<<<<<<<<<
 *     os.system('clear || cls')
 * 
 */

/* Python wrapper */
static PyObject *__pyx_pw_6cryptz_1clear(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static PyMethodDef __pyx_mdef_6cryptz_1clear = {"clear", (PyCFunction)__pyx_pw_6cryptz_1clear, METH_NOARGS, 0};
static PyObject *__pyx_pw_6cryptz_1clear(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("clear (wrapper)", 0);
  __pyx_r = __pyx_pf_6cryptz_clear(__pyx_self);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6cryptz_clear(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  __Pyx_RefNannySetupContext("clear", 0);

  /* "cryptz.py":13
 *         exit(1)
 * def clear():
 *     os.system('clear || cls')             # <<<<<<<<<<<<<<
 * 
 * clear()
 */
  __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_os); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_system); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_2)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_2);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_1 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_2, __pyx_kp_u_clear_cls) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_kp_u_clear_cls);
  __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 13, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "cryptz.py":12
 *         print("\033[31m" + "Please run: python3 install.py" + "\033[0m")
 *         exit(1)
 * def clear():             # <<<<<<<<<<<<<<
 *     os.system('clear || cls')
 * 
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("cryptz.clear", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "cryptz.py":49
 * unknown15="\033[38;5;14m"
 * ##########################
 * def banner():             # <<<<<<<<<<<<<<
 *     print(unknown2 + "\n  https://github.com/doophack/cryptz\n")
 *     print(unknown15 + "   ####   #####   #   #  #####   #####  ###### ")
 */

/* Python wrapper */
static PyObject *__pyx_pw_6cryptz_3banner(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static PyMethodDef __pyx_mdef_6cryptz_3banner = {"banner", (PyCFunction)__pyx_pw_6cryptz_3banner, METH_NOARGS, 0};
static PyObject *__pyx_pw_6cryptz_3banner(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("banner (wrapper)", 0);
  __pyx_r = __pyx_pf_6cryptz_2banner(__pyx_self);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6cryptz_2banner(CYTHON_UNUSED PyObject *__pyx_self) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  __Pyx_RefNannySetupContext("banner", 0);

  /* "cryptz.py":50
 * ##########################
 * def banner():
 *     print(unknown2 + "\n  https://github.com/doophack/cryptz\n")             # <<<<<<<<<<<<<<
 *     print(unknown15 + "   ####   #####   #   #  #####   #####  ###### ")
 *     print(unknown15 + "  #    #  #    #   # #   #    #    #        # ")
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_unknown2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 50, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_kp_u_https_github_com_doophack_crypt); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 50, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 50, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "cryptz.py":51
 * def banner():
 *     print(unknown2 + "\n  https://github.com/doophack/cryptz\n")
 *     print(unknown15 + "   ####   #####   #   #  #####   #####  ###### ")             # <<<<<<<<<<<<<<
 *     print(unknown15 + "  #    #  #    #   # #   #    #    #        # ")
 *     print(unknown15 + "  #       #    #    #    #    #    #       # ")
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_unknown15); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 51, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_kp_u_); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 51, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 51, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "cryptz.py":52
 *     print(unknown2 + "\n  https://github.com/doophack/cryptz\n")
 *     print(unknown15 + "   ####   #####   #   #  #####   #####  ###### ")
 *     print(unknown15 + "  #    #  #    #   # #   #    #    #        # ")             # <<<<<<<<<<<<<<
 *     print(unknown15 + "  #       #    #    #    #    #    #       # ")
 *     print(unknown15 + "  #       #####     #    #####     #      # ")
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_unknown15); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 52, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_kp_u__2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 52, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 52, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "cryptz.py":53
 *     print(unknown15 + "   ####   #####   #   #  #####   #####  ###### ")
 *     print(unknown15 + "  #    #  #    #   # #   #    #    #        # ")
 *     print(unknown15 + "  #       #    #    #    #    #    #       # ")             # <<<<<<<<<<<<<<
 *     print(unknown15 + "  #       #####     #    #####     #      # ")
 *     print(unknown15 + "  #    #  #   #     #    #         #     # ")
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_unknown15); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_kp_u__3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 53, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "cryptz.py":54
 *     print(unknown15 + "  #    #  #    #   # #   #    #    #        # ")
 *     print(unknown15 + "  #       #    #    #    #    #    #       # ")
 *     print(unknown15 + "  #       #####     #    #####     #      # ")             # <<<<<<<<<<<<<<
 *     print(unknown15 + "  #    #  #   #     #    #         #     # ")
 *     print(unknown15 + "   ####   #    #    #    #         #    ######  \033[31m" + "v3.0" + "\033[0m \n")
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_unknown15); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_kp_u__4); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 54, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "cryptz.py":55
 *     print(unknown15 + "  #       #    #    #    #    #    #       # ")
 *     print(unknown15 + "  #       #####     #    #####     #      # ")
 *     print(unknown15 + "  #    #  #   #     #    #         #     # ")             # <<<<<<<<<<<<<<
 *     print(unknown15 + "   ####   #    #    #    #         #    ######  \033[31m" + "v3.0" + "\033[0m \n")
 *     print(unknown15 + "  made by: " + Red + "Do0pH2ck and inc0gnit0\n" + Reset)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_unknown15); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_kp_u__5); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 55, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "cryptz.py":56
 *     print(unknown15 + "  #       #####     #    #####     #      # ")
 *     print(unknown15 + "  #    #  #   #     #    #         #     # ")
 *     print(unknown15 + "   ####   #    #    #    #         #    ######  \033[31m" + "v3.0" + "\033[0m \n")             # <<<<<<<<<<<<<<
 *     print(unknown15 + "  made by: " + Red + "Do0pH2ck and inc0gnit0\n" + Reset)
 *     print(unknown15 + "  Instagram: " + Red +"benelhaj_younes(Do0pH2ck) i.nc0gnit0(inc0gnit0)\n" + Reset)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_unknown15); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_kp_u_31m); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Add(__pyx_t_2, __pyx_kp_u_v3_0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_kp_u_0m); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 56, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "cryptz.py":57
 *     print(unknown15 + "  #    #  #   #     #    #         #     # ")
 *     print(unknown15 + "   ####   #    #    #    #         #    ######  \033[31m" + "v3.0" + "\033[0m \n")
 *     print(unknown15 + "  made by: " + Red + "Do0pH2ck and inc0gnit0\n" + Reset)             # <<<<<<<<<<<<<<
 *     print(unknown15 + "  Instagram: " + Red +"benelhaj_younes(Do0pH2ck) i.nc0gnit0(inc0gnit0)\n" + Reset)
 * def main():
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_unknown15); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_kp_u_made_by); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Red); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyNumber_Add(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyNumber_Add(__pyx_t_3, __pyx_kp_u_Do0pH2ck_and_inc0gnit0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Reset); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 57, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

  /* "cryptz.py":58
 *     print(unknown15 + "   ####   #    #    #    #         #    ######  \033[31m" + "v3.0" + "\033[0m \n")
 *     print(unknown15 + "  made by: " + Red + "Do0pH2ck and inc0gnit0\n" + Reset)
 *     print(unknown15 + "  Instagram: " + Red +"benelhaj_younes(Do0pH2ck) i.nc0gnit0(inc0gnit0)\n" + Reset)             # <<<<<<<<<<<<<<
 * def main():
 *     for i in range(1):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_unknown15); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_2 = PyNumber_Add(__pyx_t_3, __pyx_kp_u_Instagram); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Red); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __pyx_t_1 = PyNumber_Add(__pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_t_3 = PyNumber_Add(__pyx_t_1, __pyx_kp_u_benelhaj_younes_Do0pH2ck_i_nc0gn); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_Reset); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = PyNumber_Add(__pyx_t_3, __pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 58, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "cryptz.py":49
 * unknown15="\033[38;5;14m"
 * ##########################
 * def banner():             # <<<<<<<<<<<<<<
 *     print(unknown2 + "\n  https://github.com/doophack/cryptz\n")
 *     print(unknown15 + "   ####   #####   #   #  #####   #####  ###### ")
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("cryptz.banner", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "cryptz.py":59
 *     print(unknown15 + "  made by: " + Red + "Do0pH2ck and inc0gnit0\n" + Reset)
 *     print(unknown15 + "  Instagram: " + Red +"benelhaj_younes(Do0pH2ck) i.nc0gnit0(inc0gnit0)\n" + Reset)
 * def main():             # <<<<<<<<<<<<<<
 *     for i in range(1):
 *         banner()
 */

/* Python wrapper */
static PyObject *__pyx_pw_6cryptz_5main(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused); /*proto*/
static PyMethodDef __pyx_mdef_6cryptz_5main = {"main", (PyCFunction)__pyx_pw_6cryptz_5main, METH_NOARGS, 0};
static PyObject *__pyx_pw_6cryptz_5main(PyObject *__pyx_self, CYTHON_UNUSED PyObject *unused) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("main (wrapper)", 0);
  __pyx_r = __pyx_pf_6cryptz_4main(__pyx_self);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "cryptz.py":104
 *                 banner()
 *                 strings = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf"
 *                 def reverse_char(s):             # <<<<<<<<<<<<<<
 *                     return s[::-1]
 *                 def unreversed_char(s):
 */

/* Python wrapper */
static PyObject *__pyx_pw_6cryptz_4main_1reverse_char(PyObject *__pyx_self, PyObject *__pyx_v_s); /*proto*/
static PyMethodDef __pyx_mdef_6cryptz_4main_1reverse_char = {"reverse_char", (PyCFunction)__pyx_pw_6cryptz_4main_1reverse_char, METH_O, 0};
static PyObject *__pyx_pw_6cryptz_4main_1reverse_char(PyObject *__pyx_self, PyObject *__pyx_v_s) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("reverse_char (wrapper)", 0);
  __pyx_r = __pyx_pf_6cryptz_4main_reverse_char(__pyx_self, ((PyObject *)__pyx_v_s));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6cryptz_4main_reverse_char(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_s) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  __Pyx_RefNannySetupContext("reverse_char", 0);

  /* "cryptz.py":105
 *                 strings = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf"
 *                 def reverse_char(s):
 *                     return s[::-1]             # <<<<<<<<<<<<<<
 *                 def unreversed_char(s):
 *                     return s[::-1]
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_s, __pyx_slice__6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 105, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "cryptz.py":104
 *                 banner()
 *                 strings = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf"
 *                 def reverse_char(s):             # <<<<<<<<<<<<<<
 *                     return s[::-1]
 *                 def unreversed_char(s):
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("cryptz.main.reverse_char", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "cryptz.py":106
 *                 def reverse_char(s):
 *                     return s[::-1]
 *                 def unreversed_char(s):             # <<<<<<<<<<<<<<
 *                     return s[::-1]
 *                 def add_string(s):
 */

/* Python wrapper */
static PyObject *__pyx_pw_6cryptz_4main_3unreversed_char(PyObject *__pyx_self, PyObject *__pyx_v_s); /*proto*/
static PyMethodDef __pyx_mdef_6cryptz_4main_3unreversed_char = {"unreversed_char", (PyCFunction)__pyx_pw_6cryptz_4main_3unreversed_char, METH_O, 0};
static PyObject *__pyx_pw_6cryptz_4main_3unreversed_char(PyObject *__pyx_self, PyObject *__pyx_v_s) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("unreversed_char (wrapper)", 0);
  __pyx_r = __pyx_pf_6cryptz_4main_2unreversed_char(__pyx_self, ((PyObject *)__pyx_v_s));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6cryptz_4main_2unreversed_char(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_s) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  __Pyx_RefNannySetupContext("unreversed_char", 0);

  /* "cryptz.py":107
 *                     return s[::-1]
 *                 def unreversed_char(s):
 *                     return s[::-1]             # <<<<<<<<<<<<<<
 *                 def add_string(s):
 *                     return s[:5] + strings + s[5:]
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_s, __pyx_slice__6); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 107, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "cryptz.py":106
 *                 def reverse_char(s):
 *                     return s[::-1]
 *                 def unreversed_char(s):             # <<<<<<<<<<<<<<
 *                     return s[::-1]
 *                 def add_string(s):
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("cryptz.main.unreversed_char", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "cryptz.py":108
 *                 def unreversed_char(s):
 *                     return s[::-1]
 *                 def add_string(s):             # <<<<<<<<<<<<<<
 *                     return s[:5] + strings + s[5:]
 *                 def rem_string(text, char):
 */

/* Python wrapper */
static PyObject *__pyx_pw_6cryptz_4main_5add_string(PyObject *__pyx_self, PyObject *__pyx_v_s); /*proto*/
static PyMethodDef __pyx_mdef_6cryptz_4main_5add_string = {"add_string", (PyCFunction)__pyx_pw_6cryptz_4main_5add_string, METH_O, 0};
static PyObject *__pyx_pw_6cryptz_4main_5add_string(PyObject *__pyx_self, PyObject *__pyx_v_s) {
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("add_string (wrapper)", 0);
  __pyx_r = __pyx_pf_6cryptz_4main_4add_string(__pyx_self, ((PyObject *)__pyx_v_s));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6cryptz_4main_4add_string(PyObject *__pyx_self, PyObject *__pyx_v_s) {
  struct __pyx_obj_6cryptz___pyx_scope_struct__main *__pyx_cur_scope;
  struct __pyx_obj_6cryptz___pyx_scope_struct__main *__pyx_outer_scope;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  __Pyx_RefNannySetupContext("add_string", 0);
  __pyx_outer_scope = (struct __pyx_obj_6cryptz___pyx_scope_struct__main *) __Pyx_CyFunction_GetClosure(__pyx_self);
  __pyx_cur_scope = __pyx_outer_scope;

  /* "cryptz.py":109
 *                     return s[::-1]
 *                 def add_string(s):
 *                     return s[:5] + strings + s[5:]             # <<<<<<<<<<<<<<
 *                 def rem_string(text, char):
 *                     resul = ""
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = __Pyx_PyObject_GetSlice(__pyx_v_s, 0, 5, NULL, NULL, &__pyx_slice__7, 0, 1, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 109, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (unlikely(!__pyx_cur_scope->__pyx_v_strings)) { __Pyx_RaiseClosureNameError("strings"); __PYX_ERR(0, 109, __pyx_L1_error) }
  __pyx_t_2 = PyNumber_Add(__pyx_t_1, __pyx_cur_scope->__pyx_v_strings); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 109, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyObject_GetSlice(__pyx_v_s, 5, 0, NULL, NULL, &__pyx_slice__8, 1, 0, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 109, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = PyNumber_Add(__pyx_t_2, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 109, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_r = __pyx_t_3;
  __pyx_t_3 = 0;
  goto __pyx_L0;

  /* "cryptz.py":108
 *                 def unreversed_char(s):
 *                     return s[::-1]
 *                 def add_string(s):             # <<<<<<<<<<<<<<
 *                     return s[:5] + strings + s[5:]
 *                 def rem_string(text, char):
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_AddTraceback("cryptz.main.add_string", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "cryptz.py":110
 *                 def add_string(s):
 *                     return s[:5] + strings + s[5:]
 *                 def rem_string(text, char):             # <<<<<<<<<<<<<<
 *                     resul = ""
 *                     for c in text:
 */

/* Python wrapper */
static PyObject *__pyx_pw_6cryptz_4main_7rem_string(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_6cryptz_4main_7rem_string = {"rem_string", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_6cryptz_4main_7rem_string, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_6cryptz_4main_7rem_string(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyObject *__pyx_v_text = 0;
  PyObject *__pyx_v_char = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("rem_string (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_text,&__pyx_n_s_char,0};
    PyObject* values[2] = {0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_text)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_char)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("rem_string", 1, 2, 2, 1); __PYX_ERR(0, 110, __pyx_L3_error)
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "rem_string") < 0)) __PYX_ERR(0, 110, __pyx_L3_error)
      }
    } else if (PyTuple_GET_SIZE(__pyx_args) != 2) {
      goto __pyx_L5_argtuple_error;
    } else {
      values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
      values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
    }
    __pyx_v_text = values[0];
    __pyx_v_char = values[1];
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("rem_string", 1, 2, 2, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 110, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("cryptz.main.rem_string", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  __pyx_r = __pyx_pf_6cryptz_4main_6rem_string(__pyx_self, __pyx_v_text, __pyx_v_char);

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_6cryptz_4main_6rem_string(CYTHON_UNUSED PyObject *__pyx_self, PyObject *__pyx_v_text, PyObject *__pyx_v_char) {
  PyObject *__pyx_v_resul = NULL;
  PyObject *__pyx_v_c = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *(*__pyx_t_3)(PyObject *);
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  PyObject *__pyx_t_6 = NULL;
  int __pyx_t_7;
  PyObject *__pyx_t_8 = NULL;
  __Pyx_RefNannySetupContext("rem_string", 0);

  /* "cryptz.py":111
 *                     return s[:5] + strings + s[5:]
 *                 def rem_string(text, char):
 *                     resul = ""             # <<<<<<<<<<<<<<
 *                     for c in text:
 *                         if c != char:
 */
  __Pyx_INCREF(__pyx_kp_u__9);
  __pyx_v_resul = __pyx_kp_u__9;

  /* "cryptz.py":112
 *                 def rem_string(text, char):
 *                     resul = ""
 *                     for c in text:             # <<<<<<<<<<<<<<
 *                         if c != char:
 *                             resul += c
 */
  if (likely(PyList_CheckExact(__pyx_v_text)) || PyTuple_CheckExact(__pyx_v_text)) {
    __pyx_t_1 = __pyx_v_text; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
    __pyx_t_3 = NULL;
  } else {
    __pyx_t_2 = -1; __pyx_t_1 = PyObject_GetIter(__pyx_v_text); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 112, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = Py_TYPE(__pyx_t_1)->tp_iternext; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 112, __pyx_L1_error)
  }
  for (;;) {
    if (likely(!__pyx_t_3)) {
      if (likely(PyList_CheckExact(__pyx_t_1))) {
        if (__pyx_t_2 >= PyList_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyList_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 112, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 112, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      } else {
        if (__pyx_t_2 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_4 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_4); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(0, 112, __pyx_L1_error)
        #else
        __pyx_t_4 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 112, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        #endif
      }
    } else {
      __pyx_t_4 = __pyx_t_3(__pyx_t_1);
      if (unlikely(!__pyx_t_4)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 112, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_4);
    }
    __Pyx_XDECREF_SET(__pyx_v_c, __pyx_t_4);
    __pyx_t_4 = 0;

    /* "cryptz.py":113
 *                     resul = ""
 *                     for c in text:
 *                         if c != char:             # <<<<<<<<<<<<<<
 *                             resul += c
 *                     return text.replace(char, "")
 */
    __pyx_t_4 = PyObject_RichCompare(__pyx_v_c, __pyx_v_char, Py_NE); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 113, __pyx_L1_error)
    __pyx_t_5 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_5 < 0)) __PYX_ERR(0, 113, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (__pyx_t_5) {

      /* "cryptz.py":114
 *                     for c in text:
 *                         if c != char:
 *                             resul += c             # <<<<<<<<<<<<<<
 *                     return text.replace(char, "")
 *                 choice = input(unknown + "  Do You Want To Encrypt Or Decrypt" + unknown3 + " [E/D,e/d]: " + Reset)
 */
      __pyx_t_4 = PyNumber_InPlaceAdd(__pyx_v_resul, __pyx_v_c); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 114, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF_SET(__pyx_v_resul, __pyx_t_4);
      __pyx_t_4 = 0;

      /* "cryptz.py":113
 *                     resul = ""
 *                     for c in text:
 *                         if c != char:             # <<<<<<<<<<<<<<
 *                             resul += c
 *                     return text.replace(char, "")
 */
    }

    /* "cryptz.py":112
 *                 def rem_string(text, char):
 *                     resul = ""
 *                     for c in text:             # <<<<<<<<<<<<<<
 *                         if c != char:
 *                             resul += c
 */
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "cryptz.py":115
 *                         if c != char:
 *                             resul += c
 *                     return text.replace(char, "")             # <<<<<<<<<<<<<<
 *                 choice = input(unknown + "  Do You Want To Encrypt Or Decrypt" + unknown3 + " [E/D,e/d]: " + Reset)
 *                 print("\n")
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_v_text, __pyx_n_s_replace); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 115, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_6 = NULL;
  __pyx_t_7 = 0;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_4))) {
    __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_4);
    if (likely(__pyx_t_6)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
      __Pyx_INCREF(__pyx_t_6);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_4, function);
      __pyx_t_7 = 1;
    }
  }
  #if CYTHON_FAST_PYCALL
  if (PyFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_v_char, __pyx_kp_u__9};
    __pyx_t_1 = __Pyx_PyFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_7, 2+__pyx_t_7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 115, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  #if CYTHON_FAST_PYCCALL
  if (__Pyx_PyFastCFunction_Check(__pyx_t_4)) {
    PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_v_char, __pyx_kp_u__9};
    __pyx_t_1 = __Pyx_PyCFunction_FastCall(__pyx_t_4, __pyx_temp+1-__pyx_t_7, 2+__pyx_t_7); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 115, __pyx_L1_error)
    __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
    __Pyx_GOTREF(__pyx_t_1);
  } else
  #endif
  {
    __pyx_t_8 = PyTuple_New(2+__pyx_t_7); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 115, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    if (__pyx_t_6) {
      __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_8, 0, __pyx_t_6); __pyx_t_6 = NULL;
    }
    __Pyx_INCREF(__pyx_v_char);
    __Pyx_GIVEREF(__pyx_v_char);
    PyTuple_SET_ITEM(__pyx_t_8, 0+__pyx_t_7, __pyx_v_char);
    __Pyx_INCREF(__pyx_kp_u__9);
    __Pyx_GIVEREF(__pyx_kp_u__9);
    PyTuple_SET_ITEM(__pyx_t_8, 1+__pyx_t_7, __pyx_kp_u__9);
    __pyx_t_1 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_t_8, NULL); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 115, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  }
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "cryptz.py":110
 *                 def add_string(s):
 *                     return s[:5] + strings + s[5:]
 *                 def rem_string(text, char):             # <<<<<<<<<<<<<<
 *                     resul = ""
 *                     for c in text:
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("cryptz.main.rem_string", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_resul);
  __Pyx_XDECREF(__pyx_v_c);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "cryptz.py":59
 *     print(unknown15 + "  made by: " + Red + "Do0pH2ck and inc0gnit0\n" + Reset)
 *     print(unknown15 + "  Instagram: " + Red +"benelhaj_younes(Do0pH2ck) i.nc0gnit0(inc0gnit0)\n" + Reset)
 * def main():             # <<<<<<<<<<<<<<
 *     for i in range(1):
 *         banner()
 */

static PyObject *__pyx_pf_6cryptz_4main(CYTHON_UNUSED PyObject *__pyx_self) {
  struct __pyx_obj_6cryptz___pyx_scope_struct__main *__pyx_cur_scope;
  CYTHON_UNUSED PyObject *__pyx_v_i = NULL;
  PyObject *__pyx_v_password = NULL;
  PyObject *__pyx_v_db = NULL;
  PyObject *__pyx_v_connect1 = NULL;
  PyObject *__pyx_v_catch_pass = NULL;
  PyObject *__pyx_v_result = NULL;
  PyObject *__pyx_v_reverse_char = 0;
  PyObject *__pyx_v_unreversed_char = 0;
  PyObject *__pyx_v_add_string = 0;
  PyObject *__pyx_v_rem_string = 0;
  PyObject *__pyx_v_choice = NULL;
  PyObject *__pyx_v_data = NULL;
  PyObject *__pyx_v_encode1 = NULL;
  PyObject *__pyx_v_dec = NULL;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  long __pyx_t_1;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  PyObject *__pyx_t_10 = NULL;
  int __pyx_t_11;
  int __pyx_t_12;
  int __pyx_t_13;
  PyObject *__pyx_t_14 = NULL;
  Py_ssize_t __pyx_t_15;
  PyObject *(*__pyx_t_16)(PyObject *);
  __Pyx_RefNannySetupContext("main", 0);
  __pyx_cur_scope = (struct __pyx_obj_6cryptz___pyx_scope_struct__main *)__pyx_tp_new_6cryptz___pyx_scope_struct__main(__pyx_ptype_6cryptz___pyx_scope_struct__main, __pyx_empty_tuple, NULL);
  if (unlikely(!__pyx_cur_scope)) {
    __pyx_cur_scope = ((struct __pyx_obj_6cryptz___pyx_scope_struct__main *)Py_None);
    __Pyx_INCREF(Py_None);
    __PYX_ERR(0, 59, __pyx_L1_error)
  } else {
    __Pyx_GOTREF(__pyx_cur_scope);
  }

  /* "cryptz.py":60
 *     print(unknown15 + "  Instagram: " + Red +"benelhaj_younes(Do0pH2ck) i.nc0gnit0(inc0gnit0)\n" + Reset)
 * def main():
 *     for i in range(1):             # <<<<<<<<<<<<<<
 *         banner()
 *         password = input(unknown7 +"  Enter License Key: ")
 */
  for (__pyx_t_1 = 0; __pyx_t_1 < 1; __pyx_t_1+=1) {
    __pyx_t_2 = __Pyx_PyInt_From_long(__pyx_t_1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 60, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "cryptz.py":61
 * def main():
 *     for i in range(1):
 *         banner()             # <<<<<<<<<<<<<<
 *         password = input(unknown7 +"  Enter License Key: ")
 *         with sqlite3.connect('store.db') as db:
 */
    __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_banner); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 61, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_4 = NULL;
    if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
      __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_3);
      if (likely(__pyx_t_4)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
        __Pyx_INCREF(__pyx_t_4);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_3, function);
      }
    }
    __pyx_t_2 = (__pyx_t_4) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_4) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 61, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

    /* "cryptz.py":62
 *     for i in range(1):
 *         banner()
 *         password = input(unknown7 +"  Enter License Key: ")             # <<<<<<<<<<<<<<
 *         with sqlite3.connect('store.db') as db:
 *             connect1 = db.cursor()
 */
    __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_unknown7); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 62, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = PyNumber_Add(__pyx_t_2, __pyx_kp_u_Enter_License_Key); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 62, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_builtin_input, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 62, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_XDECREF_SET(__pyx_v_password, __pyx_t_2);
    __pyx_t_2 = 0;

    /* "cryptz.py":63
 *         banner()
 *         password = input(unknown7 +"  Enter License Key: ")
 *         with sqlite3.connect('store.db') as db:             # <<<<<<<<<<<<<<
 *             connect1 = db.cursor()
 *         catch_pass = ("SELECT * FROM passman WHERE licensekey = ?")
 */
    /*with:*/ {
      __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_sqlite3); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 63, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_3, __pyx_n_s_connect); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 63, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_3 = NULL;
      if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_4))) {
        __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_4);
        if (likely(__pyx_t_3)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_4);
          __Pyx_INCREF(__pyx_t_3);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_4, function);
        }
      }
      __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_4, __pyx_t_3, __pyx_kp_u_store_db) : __Pyx_PyObject_CallOneArg(__pyx_t_4, __pyx_kp_u_store_db);
      __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 63, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_2);
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_5 = __Pyx_PyObject_LookupSpecial(__pyx_t_2, __pyx_n_s_exit_2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 63, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __pyx_t_3 = __Pyx_PyObject_LookupSpecial(__pyx_t_2, __pyx_n_s_enter); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 63, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_6 = NULL;
      if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_3))) {
        __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_3);
        if (likely(__pyx_t_6)) {
          PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
          __Pyx_INCREF(__pyx_t_6);
          __Pyx_INCREF(function);
          __Pyx_DECREF_SET(__pyx_t_3, function);
        }
      }
      __pyx_t_4 = (__pyx_t_6) ? __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_6) : __Pyx_PyObject_CallNoArg(__pyx_t_3);
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 63, __pyx_L5_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_3 = __pyx_t_4;
      __pyx_t_4 = 0;
      __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
      /*try:*/ {
        {
          __Pyx_PyThreadState_declare
          __Pyx_PyThreadState_assign
          __Pyx_ExceptionSave(&__pyx_t_7, &__pyx_t_8, &__pyx_t_9);
          __Pyx_XGOTREF(__pyx_t_7);
          __Pyx_XGOTREF(__pyx_t_8);
          __Pyx_XGOTREF(__pyx_t_9);
          /*try:*/ {
            __Pyx_XDECREF_SET(__pyx_v_db, __pyx_t_3);
            __pyx_t_3 = 0;

            /* "cryptz.py":64
 *         password = input(unknown7 +"  Enter License Key: ")
 *         with sqlite3.connect('store.db') as db:
 *             connect1 = db.cursor()             # <<<<<<<<<<<<<<
 *         catch_pass = ("SELECT * FROM passman WHERE licensekey = ?")
 *         connect1.execute(catch_pass, [(password)])
 */
            __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_db, __pyx_n_s_cursor); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 64, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_2);
            __pyx_t_4 = NULL;
            if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
              __pyx_t_4 = PyMethod_GET_SELF(__pyx_t_2);
              if (likely(__pyx_t_4)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
                __Pyx_INCREF(__pyx_t_4);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_2, function);
              }
            }
            __pyx_t_3 = (__pyx_t_4) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_4) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
            __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
            if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 64, __pyx_L11_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
            __Pyx_XDECREF_SET(__pyx_v_connect1, __pyx_t_3);
            __pyx_t_3 = 0;

            /* "cryptz.py":63
 *         banner()
 *         password = input(unknown7 +"  Enter License Key: ")
 *         with sqlite3.connect('store.db') as db:             # <<<<<<<<<<<<<<
 *             connect1 = db.cursor()
 *         catch_pass = ("SELECT * FROM passman WHERE licensekey = ?")
 */
          }
          __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
          __Pyx_XDECREF(__pyx_t_8); __pyx_t_8 = 0;
          __Pyx_XDECREF(__pyx_t_9); __pyx_t_9 = 0;
          goto __pyx_L18_try_end;
          __pyx_L11_error:;
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
          __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
          /*except:*/ {
            __Pyx_AddTraceback("cryptz.main", __pyx_clineno, __pyx_lineno, __pyx_filename);
            if (__Pyx_GetException(&__pyx_t_3, &__pyx_t_2, &__pyx_t_4) < 0) __PYX_ERR(0, 63, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_GOTREF(__pyx_t_2);
            __Pyx_GOTREF(__pyx_t_4);
            __pyx_t_6 = PyTuple_Pack(3, __pyx_t_3, __pyx_t_2, __pyx_t_4); if (unlikely(!__pyx_t_6)) __PYX_ERR(0, 63, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_6);
            __pyx_t_10 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_t_6, NULL);
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __Pyx_DECREF(__pyx_t_6); __pyx_t_6 = 0;
            if (unlikely(!__pyx_t_10)) __PYX_ERR(0, 63, __pyx_L13_except_error)
            __Pyx_GOTREF(__pyx_t_10);
            __pyx_t_11 = __Pyx_PyObject_IsTrue(__pyx_t_10);
            __Pyx_DECREF(__pyx_t_10); __pyx_t_10 = 0;
            if (__pyx_t_11 < 0) __PYX_ERR(0, 63, __pyx_L13_except_error)
            __pyx_t_12 = ((!(__pyx_t_11 != 0)) != 0);
            if (__pyx_t_12) {
              __Pyx_GIVEREF(__pyx_t_3);
              __Pyx_GIVEREF(__pyx_t_2);
              __Pyx_XGIVEREF(__pyx_t_4);
              __Pyx_ErrRestoreWithState(__pyx_t_3, __pyx_t_2, __pyx_t_4);
              __pyx_t_3 = 0; __pyx_t_2 = 0; __pyx_t_4 = 0; 
              __PYX_ERR(0, 63, __pyx_L13_except_error)
            }
            __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
            __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
            __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
            goto __pyx_L12_exception_handled;
          }
          __pyx_L13_except_error:;
          __Pyx_XGIVEREF(__pyx_t_7);
          __Pyx_XGIVEREF(__pyx_t_8);
          __Pyx_XGIVEREF(__pyx_t_9);
          __Pyx_ExceptionReset(__pyx_t_7, __pyx_t_8, __pyx_t_9);
          goto __pyx_L1_error;
          __pyx_L12_exception_handled:;
          __Pyx_XGIVEREF(__pyx_t_7);
          __Pyx_XGIVEREF(__pyx_t_8);
          __Pyx_XGIVEREF(__pyx_t_9);
          __Pyx_ExceptionReset(__pyx_t_7, __pyx_t_8, __pyx_t_9);
          __pyx_L18_try_end:;
        }
      }
      /*finally:*/ {
        /*normal exit:*/{
          if (__pyx_t_5) {
            __pyx_t_9 = __Pyx_PyObject_Call(__pyx_t_5, __pyx_tuple__10, NULL);
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 63, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_9);
            __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
          }
          goto __pyx_L10;
        }
        __pyx_L10:;
      }
      goto __pyx_L22;
      __pyx_L5_error:;
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      goto __pyx_L1_error;
      __pyx_L22:;
    }

    /* "cryptz.py":65
 *         with sqlite3.connect('store.db') as db:
 *             connect1 = db.cursor()
 *         catch_pass = ("SELECT * FROM passman WHERE licensekey = ?")             # <<<<<<<<<<<<<<
 *         connect1.execute(catch_pass, [(password)])
 *         result = connect1.fetchall()
 */
    __Pyx_INCREF(__pyx_kp_u_SELECT_FROM_passman_WHERE_licens);
    __Pyx_XDECREF_SET(__pyx_v_catch_pass, __pyx_kp_u_SELECT_FROM_passman_WHERE_licens);

    /* "cryptz.py":66
 *             connect1 = db.cursor()
 *         catch_pass = ("SELECT * FROM passman WHERE licensekey = ?")
 *         connect1.execute(catch_pass, [(password)])             # <<<<<<<<<<<<<<
 *         result = connect1.fetchall()
 *         if result:
 */
    if (unlikely(!__pyx_v_connect1)) { __Pyx_RaiseUnboundLocalError("connect1"); __PYX_ERR(0, 66, __pyx_L1_error) }
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_connect1, __pyx_n_s_execute); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 66, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_3 = PyList_New(1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 66, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_INCREF(__pyx_v_password);
    __Pyx_GIVEREF(__pyx_v_password);
    PyList_SET_ITEM(__pyx_t_3, 0, __pyx_v_password);
    __pyx_t_6 = NULL;
    __pyx_t_13 = 0;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_6)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_6);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
        __pyx_t_13 = 1;
      }
    }
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(__pyx_t_2)) {
      PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_v_catch_pass, __pyx_t_3};
      __pyx_t_4 = __Pyx_PyFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 66, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    } else
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(__pyx_t_2)) {
      PyObject *__pyx_temp[3] = {__pyx_t_6, __pyx_v_catch_pass, __pyx_t_3};
      __pyx_t_4 = __Pyx_PyCFunction_FastCall(__pyx_t_2, __pyx_temp+1-__pyx_t_13, 2+__pyx_t_13); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 66, __pyx_L1_error)
      __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    } else
    #endif
    {
      __pyx_t_14 = PyTuple_New(2+__pyx_t_13); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 66, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_14);
      if (__pyx_t_6) {
        __Pyx_GIVEREF(__pyx_t_6); PyTuple_SET_ITEM(__pyx_t_14, 0, __pyx_t_6); __pyx_t_6 = NULL;
      }
      __Pyx_INCREF(__pyx_v_catch_pass);
      __Pyx_GIVEREF(__pyx_v_catch_pass);
      PyTuple_SET_ITEM(__pyx_t_14, 0+__pyx_t_13, __pyx_v_catch_pass);
      __Pyx_GIVEREF(__pyx_t_3);
      PyTuple_SET_ITEM(__pyx_t_14, 1+__pyx_t_13, __pyx_t_3);
      __pyx_t_3 = 0;
      __pyx_t_4 = __Pyx_PyObject_Call(__pyx_t_2, __pyx_t_14, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 66, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
    }
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

    /* "cryptz.py":67
 *         catch_pass = ("SELECT * FROM passman WHERE licensekey = ?")
 *         connect1.execute(catch_pass, [(password)])
 *         result = connect1.fetchall()             # <<<<<<<<<<<<<<
 *         if result:
 *             for i in result:
 */
    if (unlikely(!__pyx_v_connect1)) { __Pyx_RaiseUnboundLocalError("connect1"); __PYX_ERR(0, 67, __pyx_L1_error) }
    __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_v_connect1, __pyx_n_s_fetchall); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 67, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_14 = NULL;
    if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
      __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_2);
      if (likely(__pyx_t_14)) {
        PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
        __Pyx_INCREF(__pyx_t_14);
        __Pyx_INCREF(function);
        __Pyx_DECREF_SET(__pyx_t_2, function);
      }
    }
    __pyx_t_4 = (__pyx_t_14) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_14) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
    __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
    if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 67, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF_SET(__pyx_v_result, __pyx_t_4);
    __pyx_t_4 = 0;

    /* "cryptz.py":68
 *         connect1.execute(catch_pass, [(password)])
 *         result = connect1.fetchall()
 *         if result:             # <<<<<<<<<<<<<<
 *             for i in result:
 *                 print(unknown + "\n  Access Granted!!!")
 */
    __pyx_t_12 = __Pyx_PyObject_IsTrue(__pyx_v_result); if (unlikely(__pyx_t_12 < 0)) __PYX_ERR(0, 68, __pyx_L1_error)
    if (__pyx_t_12) {

      /* "cryptz.py":69
 *         result = connect1.fetchall()
 *         if result:
 *             for i in result:             # <<<<<<<<<<<<<<
 *                 print(unknown + "\n  Access Granted!!!")
 *                 sl(3)
 */
      if (likely(PyList_CheckExact(__pyx_v_result)) || PyTuple_CheckExact(__pyx_v_result)) {
        __pyx_t_4 = __pyx_v_result; __Pyx_INCREF(__pyx_t_4); __pyx_t_15 = 0;
        __pyx_t_16 = NULL;
      } else {
        __pyx_t_15 = -1; __pyx_t_4 = PyObject_GetIter(__pyx_v_result); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 69, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        __pyx_t_16 = Py_TYPE(__pyx_t_4)->tp_iternext; if (unlikely(!__pyx_t_16)) __PYX_ERR(0, 69, __pyx_L1_error)
      }
      for (;;) {
        if (likely(!__pyx_t_16)) {
          if (likely(PyList_CheckExact(__pyx_t_4))) {
            if (__pyx_t_15 >= PyList_GET_SIZE(__pyx_t_4)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_2 = PyList_GET_ITEM(__pyx_t_4, __pyx_t_15); __Pyx_INCREF(__pyx_t_2); __pyx_t_15++; if (unlikely(0 < 0)) __PYX_ERR(0, 69, __pyx_L1_error)
            #else
            __pyx_t_2 = PySequence_ITEM(__pyx_t_4, __pyx_t_15); __pyx_t_15++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 69, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_2);
            #endif
          } else {
            if (__pyx_t_15 >= PyTuple_GET_SIZE(__pyx_t_4)) break;
            #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
            __pyx_t_2 = PyTuple_GET_ITEM(__pyx_t_4, __pyx_t_15); __Pyx_INCREF(__pyx_t_2); __pyx_t_15++; if (unlikely(0 < 0)) __PYX_ERR(0, 69, __pyx_L1_error)
            #else
            __pyx_t_2 = PySequence_ITEM(__pyx_t_4, __pyx_t_15); __pyx_t_15++; if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 69, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_2);
            #endif
          }
        } else {
          __pyx_t_2 = __pyx_t_16(__pyx_t_4);
          if (unlikely(!__pyx_t_2)) {
            PyObject* exc_type = PyErr_Occurred();
            if (exc_type) {
              if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
              else __PYX_ERR(0, 69, __pyx_L1_error)
            }
            break;
          }
          __Pyx_GOTREF(__pyx_t_2);
        }
        __Pyx_DECREF_SET(__pyx_v_i, __pyx_t_2);
        __pyx_t_2 = 0;

        /* "cryptz.py":70
 *         if result:
 *             for i in result:
 *                 print(unknown + "\n  Access Granted!!!")             # <<<<<<<<<<<<<<
 *                 sl(3)
 *                 print("  Started At {}".format(now))
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_unknown); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 70, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_14 = PyNumber_Add(__pyx_t_2, __pyx_kp_u_Access_Granted); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 70, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __pyx_t_2 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_14); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 70, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

        /* "cryptz.py":71
 *             for i in result:
 *                 print(unknown + "\n  Access Granted!!!")
 *                 sl(3)             # <<<<<<<<<<<<<<
 *                 print("  Started At {}".format(now))
 *                 sl(0.10)
 */
        __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_sl); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 71, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_14))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_14);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_14, function);
          }
        }
        __pyx_t_2 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_3, __pyx_int_3) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_int_3);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 71, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

        /* "cryptz.py":72
 *                 print(unknown + "\n  Access Granted!!!")
 *                 sl(3)
 *                 print("  Started At {}".format(now))             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[0%]")
 */
        __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_kp_u_Started_At, __pyx_n_s_format); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 72, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_now); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 72, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_6 = NULL;
        if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_14))) {
          __pyx_t_6 = PyMethod_GET_SELF(__pyx_t_14);
          if (likely(__pyx_t_6)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
            __Pyx_INCREF(__pyx_t_6);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_14, function);
          }
        }
        __pyx_t_2 = (__pyx_t_6) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_6, __pyx_t_3) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_t_3);
        __Pyx_XDECREF(__pyx_t_6); __pyx_t_6 = 0;
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 72, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __pyx_t_14 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_2); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 72, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":73
 *                 sl(3)
 *                 print("  Started At {}".format(now))
 *                 sl(0.10)             # <<<<<<<<<<<<<<
 *                 print("  Loading Resources...[0%]")
 *                 sl(0.10)
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sl); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 73, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_float_0_10) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_float_0_10);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 73, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":74
 *                 print("  Started At {}".format(now))
 *                 sl(0.10)
 *                 print("  Loading Resources...[0%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[10%]")
 */
        __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__11, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 74, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":75
 *                 sl(0.10)
 *                 print("  Loading Resources...[0%]")
 *                 sl(0.10)             # <<<<<<<<<<<<<<
 *                 print("  Loading Resources...[10%]")
 *                 sl(0.10)
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sl); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 75, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_float_0_10) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_float_0_10);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 75, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":76
 *                 print("  Loading Resources...[0%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[10%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[20%]")
 */
        __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__12, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 76, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":77
 *                 sl(0.10)
 *                 print("  Loading Resources...[10%]")
 *                 sl(0.10)             # <<<<<<<<<<<<<<
 *                 print("  Loading Resources...[20%]")
 *                 sl(0.10)
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sl); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 77, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_float_0_10) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_float_0_10);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 77, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":78
 *                 print("  Loading Resources...[10%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[20%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[30%]")
 */
        __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__13, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 78, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":79
 *                 sl(0.10)
 *                 print("  Loading Resources...[20%]")
 *                 sl(0.10)             # <<<<<<<<<<<<<<
 *                 print("  Loading Resources...[30%]")
 *                 sl(0.10)
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sl); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 79, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_float_0_10) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_float_0_10);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 79, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":80
 *                 print("  Loading Resources...[20%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[30%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[40%]")
 */
        __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__14, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 80, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":81
 *                 sl(0.10)
 *                 print("  Loading Resources...[30%]")
 *                 sl(0.10)             # <<<<<<<<<<<<<<
 *                 print("  Loading Resources...[40%]")
 *                 sl(0.10)
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sl); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 81, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_float_0_10) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_float_0_10);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 81, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":82
 *                 print("  Loading Resources...[30%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[40%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[50%]")
 */
        __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__15, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 82, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":83
 *                 sl(0.10)
 *                 print("  Loading Resources...[40%]")
 *                 sl(0.10)             # <<<<<<<<<<<<<<
 *                 print("  Loading Resources...[50%]")
 *                 sl(0.10)
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sl); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 83, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_float_0_10) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_float_0_10);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 83, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":84
 *                 print("  Loading Resources...[40%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[50%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[60%]")
 */
        __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__16, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 84, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":85
 *                 sl(0.10)
 *                 print("  Loading Resources...[50%]")
 *                 sl(0.10)             # <<<<<<<<<<<<<<
 *                 print("  Loading Resources...[60%]")
 *                 sl(0.10)
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sl); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 85, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_float_0_10) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_float_0_10);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 85, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":86
 *                 print("  Loading Resources...[50%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[60%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[70%]")
 */
        __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__17, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 86, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":87
 *                 sl(0.10)
 *                 print("  Loading Resources...[60%]")
 *                 sl(0.10)             # <<<<<<<<<<<<<<
 *                 print("  Loading Resources...[70%]")
 *                 sl(0.10)
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sl); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 87, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_float_0_10) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_float_0_10);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 87, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":88
 *                 print("  Loading Resources...[60%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[70%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[80%]")
 */
        __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__18, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 88, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":89
 *                 sl(0.10)
 *                 print("  Loading Resources...[70%]")
 *                 sl(0.10)             # <<<<<<<<<<<<<<
 *                 print("  Loading Resources...[80%]")
 *                 sl(0.10)
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sl); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 89, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_float_0_10) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_float_0_10);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 89, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":90
 *                 print("  Loading Resources...[70%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[80%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[90%]")
 */
        __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__19, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 90, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":91
 *                 sl(0.10)
 *                 print("  Loading Resources...[80%]")
 *                 sl(0.10)             # <<<<<<<<<<<<<<
 *                 print("  Loading Resources...[90%]")
 *                 sl(0.10)
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sl); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 91, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_float_0_10) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_float_0_10);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 91, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":92
 *                 print("  Loading Resources...[80%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[90%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[1000000000000%]")
 */
        __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__20, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 92, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":93
 *                 sl(0.10)
 *                 print("  Loading Resources...[90%]")
 *                 sl(0.10)             # <<<<<<<<<<<<<<
 *                 print("  Loading Resources...[1000000000000%]")
 *                 sl(1)
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sl); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 93, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_float_0_10) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_float_0_10);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 93, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":94
 *                 print("  Loading Resources...[90%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[1000000000000%]")             # <<<<<<<<<<<<<<
 *                 sl(1)
 *                 print("  CRYPTZ is starting!!")
 */
        __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__21, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 94, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":95
 *                 sl(0.10)
 *                 print("  Loading Resources...[1000000000000%]")
 *                 sl(1)             # <<<<<<<<<<<<<<
 *                 print("  CRYPTZ is starting!!")
 *                 print(unknown3+"""
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sl); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 95, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_int_1) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_int_1);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 95, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":96
 *                 print("  Loading Resources...[1000000000000%]")
 *                 sl(1)
 *                 print("  CRYPTZ is starting!!")             # <<<<<<<<<<<<<<
 *                 print(unknown3+"""
 *                 Welcome To CRYPTZ The Unbreakable Tool
 */
        __pyx_t_14 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__22, NULL); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 96, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":97
 *                 sl(1)
 *                 print("  CRYPTZ is starting!!")
 *                 print(unknown3+"""             # <<<<<<<<<<<<<<
 *                 Welcome To CRYPTZ The Unbreakable Tool
 *                 """)
 */
        __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_unknown3); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 97, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __pyx_t_2 = PyNumber_Add(__pyx_t_14, __pyx_kp_u_Welcome_To_CRYPTZ_The_Unbreakab); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 97, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __pyx_t_14 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_2); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 97, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":100
 *                 Welcome To CRYPTZ The Unbreakable Tool
 *                 """)
 *                 sl(3)             # <<<<<<<<<<<<<<
 *                 clear()
 *                 banner()
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_sl); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 100, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_3, __pyx_int_3) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_int_3);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 100, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":101
 *                 """)
 *                 sl(3)
 *                 clear()             # <<<<<<<<<<<<<<
 *                 banner()
 *                 strings = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf"
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_clear); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 101, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 101, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":102
 *                 sl(3)
 *                 clear()
 *                 banner()             # <<<<<<<<<<<<<<
 *                 strings = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf"
 *                 def reverse_char(s):
 */
        __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_banner); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 102, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __pyx_t_3 = NULL;
        if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_2))) {
          __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
          if (likely(__pyx_t_3)) {
            PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
            __Pyx_INCREF(__pyx_t_3);
            __Pyx_INCREF(function);
            __Pyx_DECREF_SET(__pyx_t_2, function);
          }
        }
        __pyx_t_14 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
        __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
        if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 102, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;

        /* "cryptz.py":103
 *                 clear()
 *                 banner()
 *                 strings = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf"             # <<<<<<<<<<<<<<
 *                 def reverse_char(s):
 *                     return s[::-1]
 */
        __Pyx_INCREF(__pyx_kp_u_1h3sgj5ks3erhg3h5dh23455wer32cfe);
        __Pyx_XGOTREF(__pyx_cur_scope->__pyx_v_strings);
        __Pyx_XDECREF_SET(__pyx_cur_scope->__pyx_v_strings, __pyx_kp_u_1h3sgj5ks3erhg3h5dh23455wer32cfe);
        __Pyx_GIVEREF(__pyx_kp_u_1h3sgj5ks3erhg3h5dh23455wer32cfe);

        /* "cryptz.py":104
 *                 banner()
 *                 strings = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf"
 *                 def reverse_char(s):             # <<<<<<<<<<<<<<
 *                     return s[::-1]
 *                 def unreversed_char(s):
 */
        __pyx_t_14 = __Pyx_CyFunction_NewEx(&__pyx_mdef_6cryptz_4main_1reverse_char, 0, __pyx_n_s_main_locals_reverse_char, NULL, __pyx_n_s_cryptz, __pyx_d, ((PyObject *)__pyx_codeobj__24)); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 104, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_XDECREF_SET(__pyx_v_reverse_char, __pyx_t_14);
        __pyx_t_14 = 0;

        /* "cryptz.py":106
 *                 def reverse_char(s):
 *                     return s[::-1]
 *                 def unreversed_char(s):             # <<<<<<<<<<<<<<
 *                     return s[::-1]
 *                 def add_string(s):
 */
        __pyx_t_14 = __Pyx_CyFunction_NewEx(&__pyx_mdef_6cryptz_4main_3unreversed_char, 0, __pyx_n_s_main_locals_unreversed_char, NULL, __pyx_n_s_cryptz, __pyx_d, ((PyObject *)__pyx_codeobj__26)); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 106, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_XDECREF_SET(__pyx_v_unreversed_char, __pyx_t_14);
        __pyx_t_14 = 0;

        /* "cryptz.py":108
 *                 def unreversed_char(s):
 *                     return s[::-1]
 *                 def add_string(s):             # <<<<<<<<<<<<<<
 *                     return s[:5] + strings + s[5:]
 *                 def rem_string(text, char):
 */
        __pyx_t_14 = __Pyx_CyFunction_NewEx(&__pyx_mdef_6cryptz_4main_5add_string, 0, __pyx_n_s_main_locals_add_string, ((PyObject*)__pyx_cur_scope), __pyx_n_s_cryptz, __pyx_d, ((PyObject *)__pyx_codeobj__28)); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 108, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_XDECREF_SET(__pyx_v_add_string, __pyx_t_14);
        __pyx_t_14 = 0;

        /* "cryptz.py":110
 *                 def add_string(s):
 *                     return s[:5] + strings + s[5:]
 *                 def rem_string(text, char):             # <<<<<<<<<<<<<<
 *                     resul = ""
 *                     for c in text:
 */
        __pyx_t_14 = __Pyx_CyFunction_NewEx(&__pyx_mdef_6cryptz_4main_7rem_string, 0, __pyx_n_s_main_locals_rem_string, NULL, __pyx_n_s_cryptz, __pyx_d, ((PyObject *)__pyx_codeobj__30)); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 110, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_XDECREF_SET(__pyx_v_rem_string, __pyx_t_14);
        __pyx_t_14 = 0;

        /* "cryptz.py":116
 *                             resul += c
 *                     return text.replace(char, "")
 *                 choice = input(unknown + "  Do You Want To Encrypt Or Decrypt" + unknown3 + " [E/D,e/d]: " + Reset)             # <<<<<<<<<<<<<<
 *                 print("\n")
 *                 if choice in ["E",'e']:
 */
        __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_unknown); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 116, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __pyx_t_2 = PyNumber_Add(__pyx_t_14, __pyx_kp_u_Do_You_Want_To_Encrypt_Or_Decry); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 116, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_unknown3); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 116, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __pyx_t_3 = PyNumber_Add(__pyx_t_2, __pyx_t_14); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 116, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __pyx_t_14 = PyNumber_Add(__pyx_t_3, __pyx_kp_u_E_D_e_d); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 116, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_14);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Reset); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 116, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_2 = PyNumber_Add(__pyx_t_14, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 116, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_2);
        __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_input, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 116, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
        __Pyx_XDECREF_SET(__pyx_v_choice, __pyx_t_3);
        __pyx_t_3 = 0;

        /* "cryptz.py":117
 *                     return text.replace(char, "")
 *                 choice = input(unknown + "  Do You Want To Encrypt Or Decrypt" + unknown3 + " [E/D,e/d]: " + Reset)
 *                 print("\n")             # <<<<<<<<<<<<<<
 *                 if choice in ["E",'e']:
 *                     data = input(unknown11 + "  Enter Your Plain Text Message: ")
 */
        __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__32, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 117, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

        /* "cryptz.py":118
 *                 choice = input(unknown + "  Do You Want To Encrypt Or Decrypt" + unknown3 + " [E/D,e/d]: " + Reset)
 *                 print("\n")
 *                 if choice in ["E",'e']:             # <<<<<<<<<<<<<<
 *                     data = input(unknown11 + "  Enter Your Plain Text Message: ")
 *                     print("\n")
 */
        __Pyx_INCREF(__pyx_v_choice);
        __pyx_t_3 = __pyx_v_choice;
        __pyx_t_11 = (__Pyx_PyUnicode_Equals(__pyx_t_3, __pyx_n_u_E, Py_EQ)); if (unlikely(__pyx_t_11 < 0)) __PYX_ERR(0, 118, __pyx_L1_error)
        if (!__pyx_t_11) {
        } else {
          __pyx_t_12 = __pyx_t_11;
          goto __pyx_L27_bool_binop_done;
        }
        __pyx_t_11 = (__Pyx_PyUnicode_Equals(__pyx_t_3, __pyx_n_u_e, Py_EQ)); if (unlikely(__pyx_t_11 < 0)) __PYX_ERR(0, 118, __pyx_L1_error)
        __pyx_t_12 = __pyx_t_11;
        __pyx_L27_bool_binop_done:;
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_11 = (__pyx_t_12 != 0);
        if (__pyx_t_11) {

          /* "cryptz.py":119
 *                 print("\n")
 *                 if choice in ["E",'e']:
 *                     data = input(unknown11 + "  Enter Your Plain Text Message: ")             # <<<<<<<<<<<<<<
 *                     print("\n")
 *                     data = data + strings
 */
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_unknown11); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 119, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_2 = PyNumber_Add(__pyx_t_3, __pyx_kp_u_Enter_Your_Plain_Text_Message); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 119, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_input, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 119, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_XDECREF_SET(__pyx_v_data, __pyx_t_3);
          __pyx_t_3 = 0;

          /* "cryptz.py":120
 *                 if choice in ["E",'e']:
 *                     data = input(unknown11 + "  Enter Your Plain Text Message: ")
 *                     print("\n")             # <<<<<<<<<<<<<<
 *                     data = data + strings
 *                     data = add_string(data)
 */
          __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__32, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 120, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

          /* "cryptz.py":121
 *                     data = input(unknown11 + "  Enter Your Plain Text Message: ")
 *                     print("\n")
 *                     data = data + strings             # <<<<<<<<<<<<<<
 *                     data = add_string(data)
 *                     data = reverse_char(data)
 */
          __pyx_t_3 = PyNumber_Add(__pyx_v_data, __pyx_cur_scope->__pyx_v_strings); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 121, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF_SET(__pyx_v_data, __pyx_t_3);
          __pyx_t_3 = 0;

          /* "cryptz.py":122
 *                     print("\n")
 *                     data = data + strings
 *                     data = add_string(data)             # <<<<<<<<<<<<<<
 *                     data = reverse_char(data)
 *                     data = str.encode(data)
 */
          __pyx_t_3 = __pyx_pf_6cryptz_4main_4add_string(__pyx_v_add_string, __pyx_v_data); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 122, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF_SET(__pyx_v_data, __pyx_t_3);
          __pyx_t_3 = 0;

          /* "cryptz.py":123
 *                     data = data + strings
 *                     data = add_string(data)
 *                     data = reverse_char(data)             # <<<<<<<<<<<<<<
 *                     data = str.encode(data)
 *                     encode1 = pybase64._pybase64.b64encode(data)
 */
          __pyx_t_3 = __pyx_pf_6cryptz_4main_reverse_char(__pyx_v_reverse_char, __pyx_v_data); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 123, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF_SET(__pyx_v_data, __pyx_t_3);
          __pyx_t_3 = 0;

          /* "cryptz.py":124
 *                     data = add_string(data)
 *                     data = reverse_char(data)
 *                     data = str.encode(data)             # <<<<<<<<<<<<<<
 *                     encode1 = pybase64._pybase64.b64encode(data)
 *                     encode1 = bytes.decode(encode1)
 */
          __pyx_t_2 = __Pyx_PyObject_GetAttrStr(((PyObject *)(&PyUnicode_Type)), __pyx_n_s_encode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 124, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __pyx_t_14 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
            __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_2);
            if (likely(__pyx_t_14)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
              __Pyx_INCREF(__pyx_t_14);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_2, function);
            }
          }
          __pyx_t_3 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_14, __pyx_v_data) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_data);
          __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
          if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 124, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_DECREF_SET(__pyx_v_data, __pyx_t_3);
          __pyx_t_3 = 0;

          /* "cryptz.py":125
 *                     data = reverse_char(data)
 *                     data = str.encode(data)
 *                     encode1 = pybase64._pybase64.b64encode(data)             # <<<<<<<<<<<<<<
 *                     encode1 = bytes.decode(encode1)
 *                     print(Green + encode1 + Reset)
 */
          __Pyx_GetModuleGlobalName(__pyx_t_2, __pyx_n_s_pybase64); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 125, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_pybase64_2); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 125, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_b64encode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 125, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __pyx_t_14 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
            __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_2);
            if (likely(__pyx_t_14)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
              __Pyx_INCREF(__pyx_t_14);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_2, function);
            }
          }
          __pyx_t_3 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_14, __pyx_v_data) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_data);
          __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
          if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 125, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_XDECREF_SET(__pyx_v_encode1, __pyx_t_3);
          __pyx_t_3 = 0;

          /* "cryptz.py":126
 *                     data = str.encode(data)
 *                     encode1 = pybase64._pybase64.b64encode(data)
 *                     encode1 = bytes.decode(encode1)             # <<<<<<<<<<<<<<
 *                     print(Green + encode1 + Reset)
 *                     print("\nThank You for Using CRYPTZ")
 */
          __pyx_t_2 = __Pyx_PyObject_GetAttrStr(((PyObject *)(&PyBytes_Type)), __pyx_n_s_decode); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 126, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __pyx_t_14 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
            __pyx_t_14 = PyMethod_GET_SELF(__pyx_t_2);
            if (likely(__pyx_t_14)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
              __Pyx_INCREF(__pyx_t_14);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_2, function);
            }
          }
          __pyx_t_3 = (__pyx_t_14) ? __Pyx_PyObject_Call2Args(__pyx_t_2, __pyx_t_14, __pyx_v_encode1) : __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_v_encode1);
          __Pyx_XDECREF(__pyx_t_14); __pyx_t_14 = 0;
          if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 126, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_DECREF_SET(__pyx_v_encode1, __pyx_t_3);
          __pyx_t_3 = 0;

          /* "cryptz.py":127
 *                     encode1 = pybase64._pybase64.b64encode(data)
 *                     encode1 = bytes.decode(encode1)
 *                     print(Green + encode1 + Reset)             # <<<<<<<<<<<<<<
 *                     print("\nThank You for Using CRYPTZ")
 *                     print("\n")
 */
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Green); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 127, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_2 = PyNumber_Add(__pyx_t_3, __pyx_v_encode1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 127, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Reset); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 127, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_14 = PyNumber_Add(__pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 127, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_14); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 127, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

          /* "cryptz.py":128
 *                     encode1 = bytes.decode(encode1)
 *                     print(Green + encode1 + Reset)
 *                     print("\nThank You for Using CRYPTZ")             # <<<<<<<<<<<<<<
 *                     print("\n")
 *                 elif choice in ['D','d']:
 */
          __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__33, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 128, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

          /* "cryptz.py":129
 *                     print(Green + encode1 + Reset)
 *                     print("\nThank You for Using CRYPTZ")
 *                     print("\n")             # <<<<<<<<<<<<<<
 *                 elif choice in ['D','d']:
 *                     clear()
 */
          __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__32, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 129, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

          /* "cryptz.py":118
 *                 choice = input(unknown + "  Do You Want To Encrypt Or Decrypt" + unknown3 + " [E/D,e/d]: " + Reset)
 *                 print("\n")
 *                 if choice in ["E",'e']:             # <<<<<<<<<<<<<<
 *                     data = input(unknown11 + "  Enter Your Plain Text Message: ")
 *                     print("\n")
 */
          goto __pyx_L26;
        }

        /* "cryptz.py":130
 *                     print("\nThank You for Using CRYPTZ")
 *                     print("\n")
 *                 elif choice in ['D','d']:             # <<<<<<<<<<<<<<
 *                     clear()
 *                     banner()
 */
        __Pyx_INCREF(__pyx_v_choice);
        __pyx_t_3 = __pyx_v_choice;
        __pyx_t_12 = (__Pyx_PyUnicode_Equals(__pyx_t_3, __pyx_n_u_D, Py_EQ)); if (unlikely(__pyx_t_12 < 0)) __PYX_ERR(0, 130, __pyx_L1_error)
        if (!__pyx_t_12) {
        } else {
          __pyx_t_11 = __pyx_t_12;
          goto __pyx_L29_bool_binop_done;
        }
        __pyx_t_12 = (__Pyx_PyUnicode_Equals(__pyx_t_3, __pyx_n_u_d, Py_EQ)); if (unlikely(__pyx_t_12 < 0)) __PYX_ERR(0, 130, __pyx_L1_error)
        __pyx_t_11 = __pyx_t_12;
        __pyx_L29_bool_binop_done:;
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __pyx_t_12 = (__pyx_t_11 != 0);
        if (__pyx_t_12) {

          /* "cryptz.py":131
 *                     print("\n")
 *                 elif choice in ['D','d']:
 *                     clear()             # <<<<<<<<<<<<<<
 *                     banner()
 *                     data = input(unknown11 + "Enter Your Encrypted Message: ")
 */
          __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_clear); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 131, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __pyx_t_2 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_14))) {
            __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_14);
            if (likely(__pyx_t_2)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
              __Pyx_INCREF(__pyx_t_2);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_14, function);
            }
          }
          __pyx_t_3 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_14);
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 131, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

          /* "cryptz.py":132
 *                 elif choice in ['D','d']:
 *                     clear()
 *                     banner()             # <<<<<<<<<<<<<<
 *                     data = input(unknown11 + "Enter Your Encrypted Message: ")
 *                     print("\n")
 */
          __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_banner); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 132, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __pyx_t_2 = NULL;
          if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_14))) {
            __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_14);
            if (likely(__pyx_t_2)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
              __Pyx_INCREF(__pyx_t_2);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_14, function);
            }
          }
          __pyx_t_3 = (__pyx_t_2) ? __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_t_2) : __Pyx_PyObject_CallNoArg(__pyx_t_14);
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 132, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

          /* "cryptz.py":133
 *                     clear()
 *                     banner()
 *                     data = input(unknown11 + "Enter Your Encrypted Message: ")             # <<<<<<<<<<<<<<
 *                     print("\n")
 *                     data = str.encode(data)
 */
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_unknown11); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 133, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_14 = PyNumber_Add(__pyx_t_3, __pyx_kp_u_Enter_Your_Encrypted_Message); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 133, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_input, __pyx_t_14); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 133, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_XDECREF_SET(__pyx_v_data, __pyx_t_3);
          __pyx_t_3 = 0;

          /* "cryptz.py":134
 *                     banner()
 *                     data = input(unknown11 + "Enter Your Encrypted Message: ")
 *                     print("\n")             # <<<<<<<<<<<<<<
 *                     data = str.encode(data)
 *                     dec = pybase64._pybase64.b64decode(data)
 */
          __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__32, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 134, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

          /* "cryptz.py":135
 *                     data = input(unknown11 + "Enter Your Encrypted Message: ")
 *                     print("\n")
 *                     data = str.encode(data)             # <<<<<<<<<<<<<<
 *                     dec = pybase64._pybase64.b64decode(data)
 *                     dec = bytes.decode(dec)
 */
          __pyx_t_14 = __Pyx_PyObject_GetAttrStr(((PyObject *)(&PyUnicode_Type)), __pyx_n_s_encode); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 135, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __pyx_t_2 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_14))) {
            __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_14);
            if (likely(__pyx_t_2)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
              __Pyx_INCREF(__pyx_t_2);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_14, function);
            }
          }
          __pyx_t_3 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_2, __pyx_v_data) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_v_data);
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 135, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_DECREF_SET(__pyx_v_data, __pyx_t_3);
          __pyx_t_3 = 0;

          /* "cryptz.py":136
 *                     print("\n")
 *                     data = str.encode(data)
 *                     dec = pybase64._pybase64.b64decode(data)             # <<<<<<<<<<<<<<
 *                     dec = bytes.decode(dec)
 *                     strings = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf"
 */
          __Pyx_GetModuleGlobalName(__pyx_t_14, __pyx_n_s_pybase64); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 136, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __pyx_t_2 = __Pyx_PyObject_GetAttrStr(__pyx_t_14, __pyx_n_s_pybase64_2); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 136, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __pyx_t_14 = __Pyx_PyObject_GetAttrStr(__pyx_t_2, __pyx_n_s_b64decode); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 136, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __pyx_t_2 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_14))) {
            __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_14);
            if (likely(__pyx_t_2)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
              __Pyx_INCREF(__pyx_t_2);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_14, function);
            }
          }
          __pyx_t_3 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_2, __pyx_v_data) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_v_data);
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 136, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_XDECREF_SET(__pyx_v_dec, __pyx_t_3);
          __pyx_t_3 = 0;

          /* "cryptz.py":137
 *                     data = str.encode(data)
 *                     dec = pybase64._pybase64.b64decode(data)
 *                     dec = bytes.decode(dec)             # <<<<<<<<<<<<<<
 *                     strings = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf"
 *                     dec = rem_string(dec, strings)
 */
          __pyx_t_14 = __Pyx_PyObject_GetAttrStr(((PyObject *)(&PyBytes_Type)), __pyx_n_s_decode); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 137, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __pyx_t_2 = NULL;
          if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_14))) {
            __pyx_t_2 = PyMethod_GET_SELF(__pyx_t_14);
            if (likely(__pyx_t_2)) {
              PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_14);
              __Pyx_INCREF(__pyx_t_2);
              __Pyx_INCREF(function);
              __Pyx_DECREF_SET(__pyx_t_14, function);
            }
          }
          __pyx_t_3 = (__pyx_t_2) ? __Pyx_PyObject_Call2Args(__pyx_t_14, __pyx_t_2, __pyx_v_dec) : __Pyx_PyObject_CallOneArg(__pyx_t_14, __pyx_v_dec);
          __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
          if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 137, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_DECREF_SET(__pyx_v_dec, __pyx_t_3);
          __pyx_t_3 = 0;

          /* "cryptz.py":138
 *                     dec = pybase64._pybase64.b64decode(data)
 *                     dec = bytes.decode(dec)
 *                     strings = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf"             # <<<<<<<<<<<<<<
 *                     dec = rem_string(dec, strings)
 *                     dec = unreversed_char(dec)
 */
          __Pyx_INCREF(__pyx_kp_u_1h3sgj5ks3erhg3h5dh23455wer32cfe);
          __Pyx_GOTREF(__pyx_cur_scope->__pyx_v_strings);
          __Pyx_DECREF_SET(__pyx_cur_scope->__pyx_v_strings, __pyx_kp_u_1h3sgj5ks3erhg3h5dh23455wer32cfe);
          __Pyx_GIVEREF(__pyx_kp_u_1h3sgj5ks3erhg3h5dh23455wer32cfe);

          /* "cryptz.py":139
 *                     dec = bytes.decode(dec)
 *                     strings = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf"
 *                     dec = rem_string(dec, strings)             # <<<<<<<<<<<<<<
 *                     dec = unreversed_char(dec)
 *                     dec = rem_string(dec, strings)
 */
          __pyx_t_3 = __pyx_cur_scope->__pyx_v_strings;
          __Pyx_INCREF(__pyx_t_3);
          __pyx_t_14 = __pyx_pf_6cryptz_4main_6rem_string(__pyx_v_rem_string, __pyx_v_dec, __pyx_t_3); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 139, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_DECREF_SET(__pyx_v_dec, __pyx_t_14);
          __pyx_t_14 = 0;

          /* "cryptz.py":140
 *                     strings = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf"
 *                     dec = rem_string(dec, strings)
 *                     dec = unreversed_char(dec)             # <<<<<<<<<<<<<<
 *                     dec = rem_string(dec, strings)
 *                     print(Green + dec + Reset)
 */
          __pyx_t_14 = __pyx_pf_6cryptz_4main_2unreversed_char(__pyx_v_unreversed_char, __pyx_v_dec); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 140, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF_SET(__pyx_v_dec, __pyx_t_14);
          __pyx_t_14 = 0;

          /* "cryptz.py":141
 *                     dec = rem_string(dec, strings)
 *                     dec = unreversed_char(dec)
 *                     dec = rem_string(dec, strings)             # <<<<<<<<<<<<<<
 *                     print(Green + dec + Reset)
 *                     print("\nThank You for Using CRYPTZ")
 */
          __pyx_t_14 = __pyx_cur_scope->__pyx_v_strings;
          __Pyx_INCREF(__pyx_t_14);
          __pyx_t_3 = __pyx_pf_6cryptz_4main_6rem_string(__pyx_v_rem_string, __pyx_v_dec, __pyx_t_14); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 141, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_DECREF_SET(__pyx_v_dec, __pyx_t_3);
          __pyx_t_3 = 0;

          /* "cryptz.py":142
 *                     dec = unreversed_char(dec)
 *                     dec = rem_string(dec, strings)
 *                     print(Green + dec + Reset)             # <<<<<<<<<<<<<<
 *                     print("\nThank You for Using CRYPTZ")
 *                     print("\n")
 */
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Green); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 142, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_14 = PyNumber_Add(__pyx_t_3, __pyx_v_dec); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 142, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Reset); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 142, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_2 = PyNumber_Add(__pyx_t_14, __pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 142, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 142, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

          /* "cryptz.py":143
 *                     dec = rem_string(dec, strings)
 *                     print(Green + dec + Reset)
 *                     print("\nThank You for Using CRYPTZ")             # <<<<<<<<<<<<<<
 *                     print("\n")
 *                 else:
 */
          __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__33, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 143, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

          /* "cryptz.py":144
 *                     print(Green + dec + Reset)
 *                     print("\nThank You for Using CRYPTZ")
 *                     print("\n")             # <<<<<<<<<<<<<<
 *                 else:
 *                     print(Red + """  Unknown Option Quiting...\n  Don't forget to follow us on Instagram!!\n""" + Reset)
 */
          __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__32, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 144, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

          /* "cryptz.py":130
 *                     print("\nThank You for Using CRYPTZ")
 *                     print("\n")
 *                 elif choice in ['D','d']:             # <<<<<<<<<<<<<<
 *                     clear()
 *                     banner()
 */
          goto __pyx_L26;
        }

        /* "cryptz.py":146
 *                     print("\n")
 *                 else:
 *                     print(Red + """  Unknown Option Quiting...\n  Don't forget to follow us on Instagram!!\n""" + Reset)             # <<<<<<<<<<<<<<
 *                     exit(1)
 *                 break
 */
        /*else*/ {
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Red); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 146, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_2 = PyNumber_Add(__pyx_t_3, __pyx_kp_u_Unknown_Option_Quiting_Don_t_fo); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 146, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_2);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_GetModuleGlobalName(__pyx_t_3, __pyx_n_s_Reset); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 146, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_14 = PyNumber_Add(__pyx_t_2, __pyx_t_3); if (unlikely(!__pyx_t_14)) __PYX_ERR(0, 146, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_14);
          __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_print, __pyx_t_14); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 146, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_14); __pyx_t_14 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;

          /* "cryptz.py":147
 *                 else:
 *                     print(Red + """  Unknown Option Quiting...\n  Don't forget to follow us on Instagram!!\n""" + Reset)
 *                     exit(1)             # <<<<<<<<<<<<<<
 *                 break
 *         else:
 */
          __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_exit, __pyx_tuple__34, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 147, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        }
        __pyx_L26:;

        /* "cryptz.py":148
 *                     print(Red + """  Unknown Option Quiting...\n  Don't forget to follow us on Instagram!!\n""" + Reset)
 *                     exit(1)
 *                 break             # <<<<<<<<<<<<<<
 *         else:
 *             print("  Unauthorized Access !!\n  Warning Don't Try Random Things Or You'll Be Banned!!\n  To get a License Key you will need to contact creators for one")
 */
        goto __pyx_L25_break;

        /* "cryptz.py":69
 *         result = connect1.fetchall()
 *         if result:
 *             for i in result:             # <<<<<<<<<<<<<<
 *                 print(unknown + "\n  Access Granted!!!")
 *                 sl(3)
 */
      }
      __pyx_L25_break:;
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

      /* "cryptz.py":68
 *         connect1.execute(catch_pass, [(password)])
 *         result = connect1.fetchall()
 *         if result:             # <<<<<<<<<<<<<<
 *             for i in result:
 *                 print(unknown + "\n  Access Granted!!!")
 */
      goto __pyx_L23;
    }

    /* "cryptz.py":150
 *                 break
 *         else:
 *             print("  Unauthorized Access !!\n  Warning Don't Try Random Things Or You'll Be Banned!!\n  To get a License Key you will need to contact creators for one")             # <<<<<<<<<<<<<<
 *             exit(1)
 * if __name__ == '__main__':
 */
    /*else*/ {
      __pyx_t_4 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__35, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 150, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

      /* "cryptz.py":151
 *         else:
 *             print("  Unauthorized Access !!\n  Warning Don't Try Random Things Or You'll Be Banned!!\n  To get a License Key you will need to contact creators for one")
 *             exit(1)             # <<<<<<<<<<<<<<
 * if __name__ == '__main__':
 *     main()
 */
      __pyx_t_4 = __Pyx_PyObject_Call(__pyx_builtin_exit, __pyx_tuple__34, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 151, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    }
    __pyx_L23:;
  }

  /* "cryptz.py":59
 *     print(unknown15 + "  made by: " + Red + "Do0pH2ck and inc0gnit0\n" + Reset)
 *     print(unknown15 + "  Instagram: " + Red +"benelhaj_younes(Do0pH2ck) i.nc0gnit0(inc0gnit0)\n" + Reset)
 * def main():             # <<<<<<<<<<<<<<
 *     for i in range(1):
 *         banner()
 */

  /* function exit code */
  __pyx_r = Py_None; __Pyx_INCREF(Py_None);
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_14);
  __Pyx_AddTraceback("cryptz.main", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF(__pyx_v_i);
  __Pyx_XDECREF(__pyx_v_password);
  __Pyx_XDECREF(__pyx_v_db);
  __Pyx_XDECREF(__pyx_v_connect1);
  __Pyx_XDECREF(__pyx_v_catch_pass);
  __Pyx_XDECREF(__pyx_v_result);
  __Pyx_XDECREF(__pyx_v_reverse_char);
  __Pyx_XDECREF(__pyx_v_unreversed_char);
  __Pyx_XDECREF(__pyx_v_add_string);
  __Pyx_XDECREF(__pyx_v_rem_string);
  __Pyx_XDECREF(__pyx_v_choice);
  __Pyx_XDECREF(__pyx_v_data);
  __Pyx_XDECREF(__pyx_v_encode1);
  __Pyx_XDECREF(__pyx_v_dec);
  __Pyx_DECREF(((PyObject *)__pyx_cur_scope));
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static struct __pyx_obj_6cryptz___pyx_scope_struct__main *__pyx_freelist_6cryptz___pyx_scope_struct__main[8];
static int __pyx_freecount_6cryptz___pyx_scope_struct__main = 0;

static PyObject *__pyx_tp_new_6cryptz___pyx_scope_struct__main(PyTypeObject *t, CYTHON_UNUSED PyObject *a, CYTHON_UNUSED PyObject *k) {
  PyObject *o;
  if (CYTHON_COMPILING_IN_CPYTHON && likely((__pyx_freecount_6cryptz___pyx_scope_struct__main > 0) & (t->tp_basicsize == sizeof(struct __pyx_obj_6cryptz___pyx_scope_struct__main)))) {
    o = (PyObject*)__pyx_freelist_6cryptz___pyx_scope_struct__main[--__pyx_freecount_6cryptz___pyx_scope_struct__main];
    memset(o, 0, sizeof(struct __pyx_obj_6cryptz___pyx_scope_struct__main));
    (void) PyObject_INIT(o, t);
  } else {
    o = (*t->tp_alloc)(t, 0);
    if (unlikely(!o)) return 0;
  }
  return o;
}

static void __pyx_tp_dealloc_6cryptz___pyx_scope_struct__main(PyObject *o) {
  struct __pyx_obj_6cryptz___pyx_scope_struct__main *p = (struct __pyx_obj_6cryptz___pyx_scope_struct__main *)o;
  Py_CLEAR(p->__pyx_v_strings);
  if (CYTHON_COMPILING_IN_CPYTHON && ((__pyx_freecount_6cryptz___pyx_scope_struct__main < 8) & (Py_TYPE(o)->tp_basicsize == sizeof(struct __pyx_obj_6cryptz___pyx_scope_struct__main)))) {
    __pyx_freelist_6cryptz___pyx_scope_struct__main[__pyx_freecount_6cryptz___pyx_scope_struct__main++] = ((struct __pyx_obj_6cryptz___pyx_scope_struct__main *)o);
  } else {
    (*Py_TYPE(o)->tp_free)(o);
  }
}

static PyTypeObject __pyx_type_6cryptz___pyx_scope_struct__main = {
  PyVarObject_HEAD_INIT(0, 0)
  "cryptz.__pyx_scope_struct__main", /*tp_name*/
  sizeof(struct __pyx_obj_6cryptz___pyx_scope_struct__main), /*tp_basicsize*/
  0, /*tp_itemsize*/
  __pyx_tp_dealloc_6cryptz___pyx_scope_struct__main, /*tp_dealloc*/
  0, /*tp_print*/
  0, /*tp_getattr*/
  0, /*tp_setattr*/
  #if PY_MAJOR_VERSION < 3
  0, /*tp_compare*/
  #endif
  #if PY_MAJOR_VERSION >= 3
  0, /*tp_as_async*/
  #endif
  0, /*tp_repr*/
  0, /*tp_as_number*/
  0, /*tp_as_sequence*/
  0, /*tp_as_mapping*/
  0, /*tp_hash*/
  0, /*tp_call*/
  0, /*tp_str*/
  0, /*tp_getattro*/
  0, /*tp_setattro*/
  0, /*tp_as_buffer*/
  Py_TPFLAGS_DEFAULT|Py_TPFLAGS_HAVE_VERSION_TAG|Py_TPFLAGS_CHECKTYPES|Py_TPFLAGS_HAVE_NEWBUFFER, /*tp_flags*/
  0, /*tp_doc*/
  0, /*tp_traverse*/
  0, /*tp_clear*/
  0, /*tp_richcompare*/
  0, /*tp_weaklistoffset*/
  0, /*tp_iter*/
  0, /*tp_iternext*/
  0, /*tp_methods*/
  0, /*tp_members*/
  0, /*tp_getset*/
  0, /*tp_base*/
  0, /*tp_dict*/
  0, /*tp_descr_get*/
  0, /*tp_descr_set*/
  0, /*tp_dictoffset*/
  0, /*tp_init*/
  0, /*tp_alloc*/
  __pyx_tp_new_6cryptz___pyx_scope_struct__main, /*tp_new*/
  0, /*tp_free*/
  0, /*tp_is_gc*/
  0, /*tp_bases*/
  0, /*tp_mro*/
  0, /*tp_cache*/
  0, /*tp_subclasses*/
  0, /*tp_weaklist*/
  0, /*tp_del*/
  0, /*tp_version_tag*/
  #if PY_VERSION_HEX >= 0x030400a1
  0, /*tp_finalize*/
  #endif
  #if PY_VERSION_HEX >= 0x030800b1
  0, /*tp_vectorcall*/
  #endif
};

static PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

#if PY_MAJOR_VERSION >= 3
#if CYTHON_PEP489_MULTI_PHASE_INIT
static PyObject* __pyx_pymod_create(PyObject *spec, PyModuleDef *def); /*proto*/
static int __pyx_pymod_exec_cryptz(PyObject* module); /*proto*/
static PyModuleDef_Slot __pyx_moduledef_slots[] = {
  {Py_mod_create, (void*)__pyx_pymod_create},
  {Py_mod_exec, (void*)__pyx_pymod_exec_cryptz},
  {0, NULL}
};
#endif

static struct PyModuleDef __pyx_moduledef = {
    PyModuleDef_HEAD_INIT,
    "cryptz",
    0, /* m_doc */
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    0, /* m_size */
  #else
    -1, /* m_size */
  #endif
    __pyx_methods /* m_methods */,
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    __pyx_moduledef_slots, /* m_slots */
  #else
    NULL, /* m_reload */
  #endif
    NULL, /* m_traverse */
    NULL, /* m_clear */
    NULL /* m_free */
};
#endif
#ifndef CYTHON_SMALL_CODE
#if defined(__clang__)
    #define CYTHON_SMALL_CODE
#elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
    #define CYTHON_SMALL_CODE __attribute__((cold))
#else
    #define CYTHON_SMALL_CODE
#endif
#endif

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_kp_u_, __pyx_k_, sizeof(__pyx_k_), 0, 1, 0, 0},
  {&__pyx_kp_u_0m, __pyx_k_0m, sizeof(__pyx_k_0m), 0, 1, 0, 0},
  {&__pyx_kp_u_0m_2, __pyx_k_0m_2, sizeof(__pyx_k_0m_2), 0, 1, 0, 0},
  {&__pyx_kp_u_1_30m, __pyx_k_1_30m, sizeof(__pyx_k_1_30m), 0, 1, 0, 0},
  {&__pyx_kp_u_1_31m, __pyx_k_1_31m, sizeof(__pyx_k_1_31m), 0, 1, 0, 0},
  {&__pyx_kp_u_1_33m, __pyx_k_1_33m, sizeof(__pyx_k_1_33m), 0, 1, 0, 0},
  {&__pyx_kp_u_1_34m, __pyx_k_1_34m, sizeof(__pyx_k_1_34m), 0, 1, 0, 0},
  {&__pyx_kp_u_1_36m, __pyx_k_1_36m, sizeof(__pyx_k_1_36m), 0, 1, 0, 0},
  {&__pyx_kp_u_1h3sgj5ks3erhg3h5dh23455wer32cfe, __pyx_k_1h3sgj5ks3erhg3h5dh23455wer32cfe, sizeof(__pyx_k_1h3sgj5ks3erhg3h5dh23455wer32cfe), 0, 1, 0, 0},
  {&__pyx_kp_u_31m, __pyx_k_31m, sizeof(__pyx_k_31m), 0, 1, 0, 0},
  {&__pyx_kp_u_31mPlease_run_python3_install_p, __pyx_k_31mPlease_run_python3_install_p, sizeof(__pyx_k_31mPlease_run_python3_install_p), 0, 1, 0, 0},
  {&__pyx_kp_u_35m, __pyx_k_35m, sizeof(__pyx_k_35m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_113m, __pyx_k_38_5_113m, sizeof(__pyx_k_38_5_113m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_13m, __pyx_k_38_5_13m, sizeof(__pyx_k_38_5_13m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_14m, __pyx_k_38_5_14m, sizeof(__pyx_k_38_5_14m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_160m, __pyx_k_38_5_160m, sizeof(__pyx_k_38_5_160m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_162m, __pyx_k_38_5_162m, sizeof(__pyx_k_38_5_162m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_165m, __pyx_k_38_5_165m, sizeof(__pyx_k_38_5_165m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_167m, __pyx_k_38_5_167m, sizeof(__pyx_k_38_5_167m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_198m, __pyx_k_38_5_198m, sizeof(__pyx_k_38_5_198m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_203m, __pyx_k_38_5_203m, sizeof(__pyx_k_38_5_203m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_208m, __pyx_k_38_5_208m, sizeof(__pyx_k_38_5_208m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_210m, __pyx_k_38_5_210m, sizeof(__pyx_k_38_5_210m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_49m, __pyx_k_38_5_49m, sizeof(__pyx_k_38_5_49m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_51m, __pyx_k_38_5_51m, sizeof(__pyx_k_38_5_51m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_82m, __pyx_k_38_5_82m, sizeof(__pyx_k_38_5_82m), 0, 1, 0, 0},
  {&__pyx_kp_u_38_5_91m, __pyx_k_38_5_91m, sizeof(__pyx_k_38_5_91m), 0, 1, 0, 0},
  {&__pyx_kp_u_39m, __pyx_k_39m, sizeof(__pyx_k_39m), 0, 1, 0, 0},
  {&__pyx_kp_u_95m, __pyx_k_95m, sizeof(__pyx_k_95m), 0, 1, 0, 0},
  {&__pyx_kp_u_96m, __pyx_k_96m, sizeof(__pyx_k_96m), 0, 1, 0, 0},
  {&__pyx_kp_u_Access_Granted, __pyx_k_Access_Granted, sizeof(__pyx_k_Access_Granted), 0, 1, 0, 0},
  {&__pyx_n_s_Blue, __pyx_k_Blue, sizeof(__pyx_k_Blue), 0, 0, 1, 1},
  {&__pyx_kp_u_CRYPTZ_is_starting, __pyx_k_CRYPTZ_is_starting, sizeof(__pyx_k_CRYPTZ_is_starting), 0, 1, 0, 0},
  {&__pyx_n_u_D, __pyx_k_D, sizeof(__pyx_k_D), 0, 1, 0, 1},
  {&__pyx_kp_u_Do0pH2ck_and_inc0gnit0, __pyx_k_Do0pH2ck_and_inc0gnit0, sizeof(__pyx_k_Do0pH2ck_and_inc0gnit0), 0, 1, 0, 0},
  {&__pyx_kp_u_Do_You_Want_To_Encrypt_Or_Decry, __pyx_k_Do_You_Want_To_Encrypt_Or_Decry, sizeof(__pyx_k_Do_You_Want_To_Encrypt_Or_Decry), 0, 1, 0, 0},
  {&__pyx_n_u_E, __pyx_k_E, sizeof(__pyx_k_E), 0, 1, 0, 1},
  {&__pyx_kp_u_E_D_e_d, __pyx_k_E_D_e_d, sizeof(__pyx_k_E_D_e_d), 0, 1, 0, 0},
  {&__pyx_kp_u_Enter_License_Key, __pyx_k_Enter_License_Key, sizeof(__pyx_k_Enter_License_Key), 0, 1, 0, 0},
  {&__pyx_kp_u_Enter_Your_Encrypted_Message, __pyx_k_Enter_Your_Encrypted_Message, sizeof(__pyx_k_Enter_Your_Encrypted_Message), 0, 1, 0, 0},
  {&__pyx_kp_u_Enter_Your_Plain_Text_Message, __pyx_k_Enter_Your_Plain_Text_Message, sizeof(__pyx_k_Enter_Your_Plain_Text_Message), 0, 1, 0, 0},
  {&__pyx_n_s_Green, __pyx_k_Green, sizeof(__pyx_k_Green), 0, 0, 1, 1},
  {&__pyx_n_s_Grey, __pyx_k_Grey, sizeof(__pyx_k_Grey), 0, 0, 1, 1},
  {&__pyx_n_s_ImportError, __pyx_k_ImportError, sizeof(__pyx_k_ImportError), 0, 0, 1, 1},
  {&__pyx_kp_u_Instagram, __pyx_k_Instagram, sizeof(__pyx_k_Instagram), 0, 1, 0, 0},
  {&__pyx_n_s_Light, __pyx_k_Light, sizeof(__pyx_k_Light), 0, 0, 1, 1},
  {&__pyx_kp_u_Loading_Resources_0, __pyx_k_Loading_Resources_0, sizeof(__pyx_k_Loading_Resources_0), 0, 1, 0, 0},
  {&__pyx_kp_u_Loading_Resources_10, __pyx_k_Loading_Resources_10, sizeof(__pyx_k_Loading_Resources_10), 0, 1, 0, 0},
  {&__pyx_kp_u_Loading_Resources_1000000000000, __pyx_k_Loading_Resources_1000000000000, sizeof(__pyx_k_Loading_Resources_1000000000000), 0, 1, 0, 0},
  {&__pyx_kp_u_Loading_Resources_20, __pyx_k_Loading_Resources_20, sizeof(__pyx_k_Loading_Resources_20), 0, 1, 0, 0},
  {&__pyx_kp_u_Loading_Resources_30, __pyx_k_Loading_Resources_30, sizeof(__pyx_k_Loading_Resources_30), 0, 1, 0, 0},
  {&__pyx_kp_u_Loading_Resources_40, __pyx_k_Loading_Resources_40, sizeof(__pyx_k_Loading_Resources_40), 0, 1, 0, 0},
  {&__pyx_kp_u_Loading_Resources_50, __pyx_k_Loading_Resources_50, sizeof(__pyx_k_Loading_Resources_50), 0, 1, 0, 0},
  {&__pyx_kp_u_Loading_Resources_60, __pyx_k_Loading_Resources_60, sizeof(__pyx_k_Loading_Resources_60), 0, 1, 0, 0},
  {&__pyx_kp_u_Loading_Resources_70, __pyx_k_Loading_Resources_70, sizeof(__pyx_k_Loading_Resources_70), 0, 1, 0, 0},
  {&__pyx_kp_u_Loading_Resources_80, __pyx_k_Loading_Resources_80, sizeof(__pyx_k_Loading_Resources_80), 0, 1, 0, 0},
  {&__pyx_kp_u_Loading_Resources_90, __pyx_k_Loading_Resources_90, sizeof(__pyx_k_Loading_Resources_90), 0, 1, 0, 0},
  {&__pyx_n_s_Red, __pyx_k_Red, sizeof(__pyx_k_Red), 0, 0, 1, 1},
  {&__pyx_n_s_Reset, __pyx_k_Reset, sizeof(__pyx_k_Reset), 0, 0, 1, 1},
  {&__pyx_kp_u_SELECT_FROM_passman_WHERE_licens, __pyx_k_SELECT_FROM_passman_WHERE_licens, sizeof(__pyx_k_SELECT_FROM_passman_WHERE_licens), 0, 1, 0, 0},
  {&__pyx_kp_u_Started_At, __pyx_k_Started_At, sizeof(__pyx_k_Started_At), 0, 1, 0, 0},
  {&__pyx_kp_u_Thank_You_for_Using_CRYPTZ, __pyx_k_Thank_You_for_Using_CRYPTZ, sizeof(__pyx_k_Thank_You_for_Using_CRYPTZ), 0, 1, 0, 0},
  {&__pyx_kp_u_Unauthorized_Access_Warning_Don, __pyx_k_Unauthorized_Access_Warning_Don, sizeof(__pyx_k_Unauthorized_Access_Warning_Don), 0, 1, 0, 0},
  {&__pyx_kp_u_Unknown_Option_Quiting_Don_t_fo, __pyx_k_Unknown_Option_Quiting_Don_t_fo, sizeof(__pyx_k_Unknown_Option_Quiting_Don_t_fo), 0, 1, 0, 0},
  {&__pyx_kp_u_Welcome_To_CRYPTZ_The_Unbreakab, __pyx_k_Welcome_To_CRYPTZ_The_Unbreakab, sizeof(__pyx_k_Welcome_To_CRYPTZ_The_Unbreakab), 0, 1, 0, 0},
  {&__pyx_kp_u__2, __pyx_k__2, sizeof(__pyx_k__2), 0, 1, 0, 0},
  {&__pyx_kp_u__3, __pyx_k__3, sizeof(__pyx_k__3), 0, 1, 0, 0},
  {&__pyx_kp_u__31, __pyx_k__31, sizeof(__pyx_k__31), 0, 1, 0, 0},
  {&__pyx_kp_u__38, __pyx_k__38, sizeof(__pyx_k__38), 0, 1, 0, 0},
  {&__pyx_kp_u__4, __pyx_k__4, sizeof(__pyx_k__4), 0, 1, 0, 0},
  {&__pyx_kp_u__5, __pyx_k__5, sizeof(__pyx_k__5), 0, 1, 0, 0},
  {&__pyx_kp_u__9, __pyx_k__9, sizeof(__pyx_k__9), 0, 1, 0, 0},
  {&__pyx_n_s_add_string, __pyx_k_add_string, sizeof(__pyx_k_add_string), 0, 0, 1, 1},
  {&__pyx_n_s_b64decode, __pyx_k_b64decode, sizeof(__pyx_k_b64decode), 0, 0, 1, 1},
  {&__pyx_n_s_b64encode, __pyx_k_b64encode, sizeof(__pyx_k_b64encode), 0, 0, 1, 1},
  {&__pyx_n_s_banner, __pyx_k_banner, sizeof(__pyx_k_banner), 0, 0, 1, 1},
  {&__pyx_kp_u_benelhaj_younes_Do0pH2ck_i_nc0gn, __pyx_k_benelhaj_younes_Do0pH2ck_i_nc0gn, sizeof(__pyx_k_benelhaj_younes_Do0pH2ck_i_nc0gn), 0, 1, 0, 0},
  {&__pyx_n_s_c, __pyx_k_c, sizeof(__pyx_k_c), 0, 0, 1, 1},
  {&__pyx_n_s_catch_pass, __pyx_k_catch_pass, sizeof(__pyx_k_catch_pass), 0, 0, 1, 1},
  {&__pyx_n_s_char, __pyx_k_char, sizeof(__pyx_k_char), 0, 0, 1, 1},
  {&__pyx_n_s_choice, __pyx_k_choice, sizeof(__pyx_k_choice), 0, 0, 1, 1},
  {&__pyx_n_s_clear, __pyx_k_clear, sizeof(__pyx_k_clear), 0, 0, 1, 1},
  {&__pyx_kp_u_clear_cls, __pyx_k_clear_cls, sizeof(__pyx_k_clear_cls), 0, 1, 0, 0},
  {&__pyx_n_s_cline_in_traceback, __pyx_k_cline_in_traceback, sizeof(__pyx_k_cline_in_traceback), 0, 0, 1, 1},
  {&__pyx_n_s_connect, __pyx_k_connect, sizeof(__pyx_k_connect), 0, 0, 1, 1},
  {&__pyx_n_s_connect1, __pyx_k_connect1, sizeof(__pyx_k_connect1), 0, 0, 1, 1},
  {&__pyx_n_s_cryptz, __pyx_k_cryptz, sizeof(__pyx_k_cryptz), 0, 0, 1, 1},
  {&__pyx_kp_s_cryptz_py, __pyx_k_cryptz_py, sizeof(__pyx_k_cryptz_py), 0, 0, 1, 0},
  {&__pyx_n_s_cursor, __pyx_k_cursor, sizeof(__pyx_k_cursor), 0, 0, 1, 1},
  {&__pyx_n_s_cyan, __pyx_k_cyan, sizeof(__pyx_k_cyan), 0, 0, 1, 1},
  {&__pyx_n_u_d, __pyx_k_d, sizeof(__pyx_k_d), 0, 1, 0, 1},
  {&__pyx_n_s_data, __pyx_k_data, sizeof(__pyx_k_data), 0, 0, 1, 1},
  {&__pyx_n_s_datetime, __pyx_k_datetime, sizeof(__pyx_k_datetime), 0, 0, 1, 1},
  {&__pyx_n_s_db, __pyx_k_db, sizeof(__pyx_k_db), 0, 0, 1, 1},
  {&__pyx_n_s_dec, __pyx_k_dec, sizeof(__pyx_k_dec), 0, 0, 1, 1},
  {&__pyx_n_s_decode, __pyx_k_decode, sizeof(__pyx_k_decode), 0, 0, 1, 1},
  {&__pyx_n_u_e, __pyx_k_e, sizeof(__pyx_k_e), 0, 1, 0, 1},
  {&__pyx_n_s_encode, __pyx_k_encode, sizeof(__pyx_k_encode), 0, 0, 1, 1},
  {&__pyx_n_s_encode1, __pyx_k_encode1, sizeof(__pyx_k_encode1), 0, 0, 1, 1},
  {&__pyx_n_s_enter, __pyx_k_enter, sizeof(__pyx_k_enter), 0, 0, 1, 1},
  {&__pyx_n_s_execute, __pyx_k_execute, sizeof(__pyx_k_execute), 0, 0, 1, 1},
  {&__pyx_n_s_exit, __pyx_k_exit, sizeof(__pyx_k_exit), 0, 0, 1, 1},
  {&__pyx_n_s_exit_2, __pyx_k_exit_2, sizeof(__pyx_k_exit_2), 0, 0, 1, 1},
  {&__pyx_n_s_fetchall, __pyx_k_fetchall, sizeof(__pyx_k_fetchall), 0, 0, 1, 1},
  {&__pyx_n_s_format, __pyx_k_format, sizeof(__pyx_k_format), 0, 0, 1, 1},
  {&__pyx_n_s_hour, __pyx_k_hour, sizeof(__pyx_k_hour), 0, 0, 1, 1},
  {&__pyx_kp_u_https_github_com_doophack_crypt, __pyx_k_https_github_com_doophack_crypt, sizeof(__pyx_k_https_github_com_doophack_crypt), 0, 1, 0, 0},
  {&__pyx_n_s_i, __pyx_k_i, sizeof(__pyx_k_i), 0, 0, 1, 1},
  {&__pyx_n_s_import, __pyx_k_import, sizeof(__pyx_k_import), 0, 0, 1, 1},
  {&__pyx_n_s_input, __pyx_k_input, sizeof(__pyx_k_input), 0, 0, 1, 1},
  {&__pyx_kp_u_made_by, __pyx_k_made_by, sizeof(__pyx_k_made_by), 0, 1, 0, 0},
  {&__pyx_n_s_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 0, 1, 1},
  {&__pyx_n_u_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 1, 0, 1},
  {&__pyx_n_s_main_2, __pyx_k_main_2, sizeof(__pyx_k_main_2), 0, 0, 1, 1},
  {&__pyx_n_s_main_locals_add_string, __pyx_k_main_locals_add_string, sizeof(__pyx_k_main_locals_add_string), 0, 0, 1, 1},
  {&__pyx_n_s_main_locals_rem_string, __pyx_k_main_locals_rem_string, sizeof(__pyx_k_main_locals_rem_string), 0, 0, 1, 1},
  {&__pyx_n_s_main_locals_reverse_char, __pyx_k_main_locals_reverse_char, sizeof(__pyx_k_main_locals_reverse_char), 0, 0, 1, 1},
  {&__pyx_n_s_main_locals_unreversed_char, __pyx_k_main_locals_unreversed_char, sizeof(__pyx_k_main_locals_unreversed_char), 0, 0, 1, 1},
  {&__pyx_n_s_min, __pyx_k_min, sizeof(__pyx_k_min), 0, 0, 1, 1},
  {&__pyx_n_s_minute, __pyx_k_minute, sizeof(__pyx_k_minute), 0, 0, 1, 1},
  {&__pyx_n_s_name, __pyx_k_name, sizeof(__pyx_k_name), 0, 0, 1, 1},
  {&__pyx_n_s_now, __pyx_k_now, sizeof(__pyx_k_now), 0, 0, 1, 1},
  {&__pyx_n_s_os, __pyx_k_os, sizeof(__pyx_k_os), 0, 0, 1, 1},
  {&__pyx_n_s_password, __pyx_k_password, sizeof(__pyx_k_password), 0, 0, 1, 1},
  {&__pyx_n_s_print, __pyx_k_print, sizeof(__pyx_k_print), 0, 0, 1, 1},
  {&__pyx_n_s_purple, __pyx_k_purple, sizeof(__pyx_k_purple), 0, 0, 1, 1},
  {&__pyx_n_s_pybase64, __pyx_k_pybase64, sizeof(__pyx_k_pybase64), 0, 0, 1, 1},
  {&__pyx_n_s_pybase64_2, __pyx_k_pybase64_2, sizeof(__pyx_k_pybase64_2), 0, 0, 1, 1},
  {&__pyx_n_s_range, __pyx_k_range, sizeof(__pyx_k_range), 0, 0, 1, 1},
  {&__pyx_n_s_re, __pyx_k_re, sizeof(__pyx_k_re), 0, 0, 1, 1},
  {&__pyx_n_s_rem_string, __pyx_k_rem_string, sizeof(__pyx_k_rem_string), 0, 0, 1, 1},
  {&__pyx_n_s_replace, __pyx_k_replace, sizeof(__pyx_k_replace), 0, 0, 1, 1},
  {&__pyx_n_s_resul, __pyx_k_resul, sizeof(__pyx_k_resul), 0, 0, 1, 1},
  {&__pyx_n_s_result, __pyx_k_result, sizeof(__pyx_k_result), 0, 0, 1, 1},
  {&__pyx_n_s_reverse_char, __pyx_k_reverse_char, sizeof(__pyx_k_reverse_char), 0, 0, 1, 1},
  {&__pyx_n_s_s, __pyx_k_s, sizeof(__pyx_k_s), 0, 0, 1, 1},
  {&__pyx_n_s_sec, __pyx_k_sec, sizeof(__pyx_k_sec), 0, 0, 1, 1},
  {&__pyx_n_s_second, __pyx_k_second, sizeof(__pyx_k_second), 0, 0, 1, 1},
  {&__pyx_n_s_sl, __pyx_k_sl, sizeof(__pyx_k_sl), 0, 0, 1, 1},
  {&__pyx_n_s_sleep, __pyx_k_sleep, sizeof(__pyx_k_sleep), 0, 0, 1, 1},
  {&__pyx_n_s_sqlite3, __pyx_k_sqlite3, sizeof(__pyx_k_sqlite3), 0, 0, 1, 1},
  {&__pyx_n_s_stong, __pyx_k_stong, sizeof(__pyx_k_stong), 0, 0, 1, 1},
  {&__pyx_kp_u_store_db, __pyx_k_store_db, sizeof(__pyx_k_store_db), 0, 1, 0, 0},
  {&__pyx_n_s_strings, __pyx_k_strings, sizeof(__pyx_k_strings), 0, 0, 1, 1},
  {&__pyx_n_s_sys, __pyx_k_sys, sizeof(__pyx_k_sys), 0, 0, 1, 1},
  {&__pyx_n_s_system, __pyx_k_system, sizeof(__pyx_k_system), 0, 0, 1, 1},
  {&__pyx_n_s_test, __pyx_k_test, sizeof(__pyx_k_test), 0, 0, 1, 1},
  {&__pyx_n_s_text, __pyx_k_text, sizeof(__pyx_k_text), 0, 0, 1, 1},
  {&__pyx_n_s_time, __pyx_k_time, sizeof(__pyx_k_time), 0, 0, 1, 1},
  {&__pyx_n_s_timenow, __pyx_k_timenow, sizeof(__pyx_k_timenow), 0, 0, 1, 1},
  {&__pyx_n_s_unknown, __pyx_k_unknown, sizeof(__pyx_k_unknown), 0, 0, 1, 1},
  {&__pyx_n_s_unknown10, __pyx_k_unknown10, sizeof(__pyx_k_unknown10), 0, 0, 1, 1},
  {&__pyx_n_s_unknown11, __pyx_k_unknown11, sizeof(__pyx_k_unknown11), 0, 0, 1, 1},
  {&__pyx_n_s_unknown12, __pyx_k_unknown12, sizeof(__pyx_k_unknown12), 0, 0, 1, 1},
  {&__pyx_n_s_unknown13, __pyx_k_unknown13, sizeof(__pyx_k_unknown13), 0, 0, 1, 1},
  {&__pyx_n_s_unknown14, __pyx_k_unknown14, sizeof(__pyx_k_unknown14), 0, 0, 1, 1},
  {&__pyx_n_s_unknown15, __pyx_k_unknown15, sizeof(__pyx_k_unknown15), 0, 0, 1, 1},
  {&__pyx_n_s_unknown2, __pyx_k_unknown2, sizeof(__pyx_k_unknown2), 0, 0, 1, 1},
  {&__pyx_n_s_unknown3, __pyx_k_unknown3, sizeof(__pyx_k_unknown3), 0, 0, 1, 1},
  {&__pyx_n_s_unknown4, __pyx_k_unknown4, sizeof(__pyx_k_unknown4), 0, 0, 1, 1},
  {&__pyx_n_s_unknown5, __pyx_k_unknown5, sizeof(__pyx_k_unknown5), 0, 0, 1, 1},
  {&__pyx_n_s_unknown6, __pyx_k_unknown6, sizeof(__pyx_k_unknown6), 0, 0, 1, 1},
  {&__pyx_n_s_unknown7, __pyx_k_unknown7, sizeof(__pyx_k_unknown7), 0, 0, 1, 1},
  {&__pyx_n_s_unknown8, __pyx_k_unknown8, sizeof(__pyx_k_unknown8), 0, 0, 1, 1},
  {&__pyx_n_s_unknown9, __pyx_k_unknown9, sizeof(__pyx_k_unknown9), 0, 0, 1, 1},
  {&__pyx_n_s_unreversed_char, __pyx_k_unreversed_char, sizeof(__pyx_k_unreversed_char), 0, 0, 1, 1},
  {&__pyx_kp_u_v3_0, __pyx_k_v3_0, sizeof(__pyx_k_v3_0), 0, 1, 0, 0},
  {&__pyx_n_s_yellow, __pyx_k_yellow, sizeof(__pyx_k_yellow), 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0}
};
static CYTHON_SMALL_CODE int __Pyx_InitCachedBuiltins(void) {
  __pyx_builtin_ImportError = __Pyx_GetBuiltinName(__pyx_n_s_ImportError); if (!__pyx_builtin_ImportError) __PYX_ERR(0, 9, __pyx_L1_error)
  __pyx_builtin_print = __Pyx_GetBuiltinName(__pyx_n_s_print); if (!__pyx_builtin_print) __PYX_ERR(0, 10, __pyx_L1_error)
  __pyx_builtin_exit = __Pyx_GetBuiltinName(__pyx_n_s_exit); if (!__pyx_builtin_exit) __PYX_ERR(0, 11, __pyx_L1_error)
  __pyx_builtin_range = __Pyx_GetBuiltinName(__pyx_n_s_range); if (!__pyx_builtin_range) __PYX_ERR(0, 60, __pyx_L1_error)
  __pyx_builtin_input = __Pyx_GetBuiltinName(__pyx_n_s_input); if (!__pyx_builtin_input) __PYX_ERR(0, 62, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitCachedConstants(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_InitCachedConstants", 0);

  /* "cryptz.py":105
 *                 strings = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf"
 *                 def reverse_char(s):
 *                     return s[::-1]             # <<<<<<<<<<<<<<
 *                 def unreversed_char(s):
 *                     return s[::-1]
 */
  __pyx_slice__6 = PySlice_New(Py_None, Py_None, __pyx_int_neg_1); if (unlikely(!__pyx_slice__6)) __PYX_ERR(0, 105, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_slice__6);
  __Pyx_GIVEREF(__pyx_slice__6);

  /* "cryptz.py":109
 *                     return s[::-1]
 *                 def add_string(s):
 *                     return s[:5] + strings + s[5:]             # <<<<<<<<<<<<<<
 *                 def rem_string(text, char):
 *                     resul = ""
 */
  __pyx_slice__7 = PySlice_New(Py_None, __pyx_int_5, Py_None); if (unlikely(!__pyx_slice__7)) __PYX_ERR(0, 109, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_slice__7);
  __Pyx_GIVEREF(__pyx_slice__7);
  __pyx_slice__8 = PySlice_New(__pyx_int_5, Py_None, Py_None); if (unlikely(!__pyx_slice__8)) __PYX_ERR(0, 109, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_slice__8);
  __Pyx_GIVEREF(__pyx_slice__8);

  /* "cryptz.py":63
 *         banner()
 *         password = input(unknown7 +"  Enter License Key: ")
 *         with sqlite3.connect('store.db') as db:             # <<<<<<<<<<<<<<
 *             connect1 = db.cursor()
 *         catch_pass = ("SELECT * FROM passman WHERE licensekey = ?")
 */
  __pyx_tuple__10 = PyTuple_Pack(3, Py_None, Py_None, Py_None); if (unlikely(!__pyx_tuple__10)) __PYX_ERR(0, 63, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__10);
  __Pyx_GIVEREF(__pyx_tuple__10);

  /* "cryptz.py":74
 *                 print("  Started At {}".format(now))
 *                 sl(0.10)
 *                 print("  Loading Resources...[0%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[10%]")
 */
  __pyx_tuple__11 = PyTuple_Pack(1, __pyx_kp_u_Loading_Resources_0); if (unlikely(!__pyx_tuple__11)) __PYX_ERR(0, 74, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__11);
  __Pyx_GIVEREF(__pyx_tuple__11);

  /* "cryptz.py":76
 *                 print("  Loading Resources...[0%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[10%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[20%]")
 */
  __pyx_tuple__12 = PyTuple_Pack(1, __pyx_kp_u_Loading_Resources_10); if (unlikely(!__pyx_tuple__12)) __PYX_ERR(0, 76, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__12);
  __Pyx_GIVEREF(__pyx_tuple__12);

  /* "cryptz.py":78
 *                 print("  Loading Resources...[10%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[20%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[30%]")
 */
  __pyx_tuple__13 = PyTuple_Pack(1, __pyx_kp_u_Loading_Resources_20); if (unlikely(!__pyx_tuple__13)) __PYX_ERR(0, 78, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__13);
  __Pyx_GIVEREF(__pyx_tuple__13);

  /* "cryptz.py":80
 *                 print("  Loading Resources...[20%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[30%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[40%]")
 */
  __pyx_tuple__14 = PyTuple_Pack(1, __pyx_kp_u_Loading_Resources_30); if (unlikely(!__pyx_tuple__14)) __PYX_ERR(0, 80, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__14);
  __Pyx_GIVEREF(__pyx_tuple__14);

  /* "cryptz.py":82
 *                 print("  Loading Resources...[30%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[40%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[50%]")
 */
  __pyx_tuple__15 = PyTuple_Pack(1, __pyx_kp_u_Loading_Resources_40); if (unlikely(!__pyx_tuple__15)) __PYX_ERR(0, 82, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__15);
  __Pyx_GIVEREF(__pyx_tuple__15);

  /* "cryptz.py":84
 *                 print("  Loading Resources...[40%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[50%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[60%]")
 */
  __pyx_tuple__16 = PyTuple_Pack(1, __pyx_kp_u_Loading_Resources_50); if (unlikely(!__pyx_tuple__16)) __PYX_ERR(0, 84, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__16);
  __Pyx_GIVEREF(__pyx_tuple__16);

  /* "cryptz.py":86
 *                 print("  Loading Resources...[50%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[60%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[70%]")
 */
  __pyx_tuple__17 = PyTuple_Pack(1, __pyx_kp_u_Loading_Resources_60); if (unlikely(!__pyx_tuple__17)) __PYX_ERR(0, 86, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__17);
  __Pyx_GIVEREF(__pyx_tuple__17);

  /* "cryptz.py":88
 *                 print("  Loading Resources...[60%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[70%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[80%]")
 */
  __pyx_tuple__18 = PyTuple_Pack(1, __pyx_kp_u_Loading_Resources_70); if (unlikely(!__pyx_tuple__18)) __PYX_ERR(0, 88, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__18);
  __Pyx_GIVEREF(__pyx_tuple__18);

  /* "cryptz.py":90
 *                 print("  Loading Resources...[70%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[80%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[90%]")
 */
  __pyx_tuple__19 = PyTuple_Pack(1, __pyx_kp_u_Loading_Resources_80); if (unlikely(!__pyx_tuple__19)) __PYX_ERR(0, 90, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__19);
  __Pyx_GIVEREF(__pyx_tuple__19);

  /* "cryptz.py":92
 *                 print("  Loading Resources...[80%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[90%]")             # <<<<<<<<<<<<<<
 *                 sl(0.10)
 *                 print("  Loading Resources...[1000000000000%]")
 */
  __pyx_tuple__20 = PyTuple_Pack(1, __pyx_kp_u_Loading_Resources_90); if (unlikely(!__pyx_tuple__20)) __PYX_ERR(0, 92, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__20);
  __Pyx_GIVEREF(__pyx_tuple__20);

  /* "cryptz.py":94
 *                 print("  Loading Resources...[90%]")
 *                 sl(0.10)
 *                 print("  Loading Resources...[1000000000000%]")             # <<<<<<<<<<<<<<
 *                 sl(1)
 *                 print("  CRYPTZ is starting!!")
 */
  __pyx_tuple__21 = PyTuple_Pack(1, __pyx_kp_u_Loading_Resources_1000000000000); if (unlikely(!__pyx_tuple__21)) __PYX_ERR(0, 94, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__21);
  __Pyx_GIVEREF(__pyx_tuple__21);

  /* "cryptz.py":96
 *                 print("  Loading Resources...[1000000000000%]")
 *                 sl(1)
 *                 print("  CRYPTZ is starting!!")             # <<<<<<<<<<<<<<
 *                 print(unknown3+"""
 *                 Welcome To CRYPTZ The Unbreakable Tool
 */
  __pyx_tuple__22 = PyTuple_Pack(1, __pyx_kp_u_CRYPTZ_is_starting); if (unlikely(!__pyx_tuple__22)) __PYX_ERR(0, 96, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__22);
  __Pyx_GIVEREF(__pyx_tuple__22);

  /* "cryptz.py":104
 *                 banner()
 *                 strings = "1h3sgj5ks3erhg3h5dh23455wer32cfewjkf"
 *                 def reverse_char(s):             # <<<<<<<<<<<<<<
 *                     return s[::-1]
 *                 def unreversed_char(s):
 */
  __pyx_tuple__23 = PyTuple_Pack(1, __pyx_n_s_s); if (unlikely(!__pyx_tuple__23)) __PYX_ERR(0, 104, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__23);
  __Pyx_GIVEREF(__pyx_tuple__23);
  __pyx_codeobj__24 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__23, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_cryptz_py, __pyx_n_s_reverse_char, 104, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__24)) __PYX_ERR(0, 104, __pyx_L1_error)

  /* "cryptz.py":106
 *                 def reverse_char(s):
 *                     return s[::-1]
 *                 def unreversed_char(s):             # <<<<<<<<<<<<<<
 *                     return s[::-1]
 *                 def add_string(s):
 */
  __pyx_tuple__25 = PyTuple_Pack(1, __pyx_n_s_s); if (unlikely(!__pyx_tuple__25)) __PYX_ERR(0, 106, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__25);
  __Pyx_GIVEREF(__pyx_tuple__25);
  __pyx_codeobj__26 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__25, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_cryptz_py, __pyx_n_s_unreversed_char, 106, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__26)) __PYX_ERR(0, 106, __pyx_L1_error)

  /* "cryptz.py":108
 *                 def unreversed_char(s):
 *                     return s[::-1]
 *                 def add_string(s):             # <<<<<<<<<<<<<<
 *                     return s[:5] + strings + s[5:]
 *                 def rem_string(text, char):
 */
  __pyx_tuple__27 = PyTuple_Pack(1, __pyx_n_s_s); if (unlikely(!__pyx_tuple__27)) __PYX_ERR(0, 108, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__27);
  __Pyx_GIVEREF(__pyx_tuple__27);
  __pyx_codeobj__28 = (PyObject*)__Pyx_PyCode_New(1, 0, 1, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__27, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_cryptz_py, __pyx_n_s_add_string, 108, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__28)) __PYX_ERR(0, 108, __pyx_L1_error)

  /* "cryptz.py":110
 *                 def add_string(s):
 *                     return s[:5] + strings + s[5:]
 *                 def rem_string(text, char):             # <<<<<<<<<<<<<<
 *                     resul = ""
 *                     for c in text:
 */
  __pyx_tuple__29 = PyTuple_Pack(4, __pyx_n_s_text, __pyx_n_s_char, __pyx_n_s_resul, __pyx_n_s_c); if (unlikely(!__pyx_tuple__29)) __PYX_ERR(0, 110, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__29);
  __Pyx_GIVEREF(__pyx_tuple__29);
  __pyx_codeobj__30 = (PyObject*)__Pyx_PyCode_New(2, 0, 4, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__29, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_cryptz_py, __pyx_n_s_rem_string, 110, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__30)) __PYX_ERR(0, 110, __pyx_L1_error)

  /* "cryptz.py":117
 *                     return text.replace(char, "")
 *                 choice = input(unknown + "  Do You Want To Encrypt Or Decrypt" + unknown3 + " [E/D,e/d]: " + Reset)
 *                 print("\n")             # <<<<<<<<<<<<<<
 *                 if choice in ["E",'e']:
 *                     data = input(unknown11 + "  Enter Your Plain Text Message: ")
 */
  __pyx_tuple__32 = PyTuple_Pack(1, __pyx_kp_u__31); if (unlikely(!__pyx_tuple__32)) __PYX_ERR(0, 117, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__32);
  __Pyx_GIVEREF(__pyx_tuple__32);

  /* "cryptz.py":128
 *                     encode1 = bytes.decode(encode1)
 *                     print(Green + encode1 + Reset)
 *                     print("\nThank You for Using CRYPTZ")             # <<<<<<<<<<<<<<
 *                     print("\n")
 *                 elif choice in ['D','d']:
 */
  __pyx_tuple__33 = PyTuple_Pack(1, __pyx_kp_u_Thank_You_for_Using_CRYPTZ); if (unlikely(!__pyx_tuple__33)) __PYX_ERR(0, 128, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__33);
  __Pyx_GIVEREF(__pyx_tuple__33);

  /* "cryptz.py":147
 *                 else:
 *                     print(Red + """  Unknown Option Quiting...\n  Don't forget to follow us on Instagram!!\n""" + Reset)
 *                     exit(1)             # <<<<<<<<<<<<<<
 *                 break
 *         else:
 */
  __pyx_tuple__34 = PyTuple_Pack(1, __pyx_int_1); if (unlikely(!__pyx_tuple__34)) __PYX_ERR(0, 147, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__34);
  __Pyx_GIVEREF(__pyx_tuple__34);

  /* "cryptz.py":150
 *                 break
 *         else:
 *             print("  Unauthorized Access !!\n  Warning Don't Try Random Things Or You'll Be Banned!!\n  To get a License Key you will need to contact creators for one")             # <<<<<<<<<<<<<<
 *             exit(1)
 * if __name__ == '__main__':
 */
  __pyx_tuple__35 = PyTuple_Pack(1, __pyx_kp_u_Unauthorized_Access_Warning_Don); if (unlikely(!__pyx_tuple__35)) __PYX_ERR(0, 150, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__35);
  __Pyx_GIVEREF(__pyx_tuple__35);

  /* "cryptz.py":10
 *     from time import sleep as sl
 * except ImportError:
 *         print("\033[31m" + "Please run: python3 install.py" + "\033[0m")             # <<<<<<<<<<<<<<
 *         exit(1)
 * def clear():
 */
  __pyx_tuple__36 = PyTuple_Pack(1, __pyx_kp_u_31mPlease_run_python3_install_p); if (unlikely(!__pyx_tuple__36)) __PYX_ERR(0, 10, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__36);
  __Pyx_GIVEREF(__pyx_tuple__36);

  /* "cryptz.py":12
 *         print("\033[31m" + "Please run: python3 install.py" + "\033[0m")
 *         exit(1)
 * def clear():             # <<<<<<<<<<<<<<
 *     os.system('clear || cls')
 * 
 */
  __pyx_codeobj__37 = (PyObject*)__Pyx_PyCode_New(0, 0, 0, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_cryptz_py, __pyx_n_s_clear, 12, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__37)) __PYX_ERR(0, 12, __pyx_L1_error)

  /* "cryptz.py":49
 * unknown15="\033[38;5;14m"
 * ##########################
 * def banner():             # <<<<<<<<<<<<<<
 *     print(unknown2 + "\n  https://github.com/doophack/cryptz\n")
 *     print(unknown15 + "   ####   #####   #   #  #####   #####  ###### ")
 */
  __pyx_codeobj__39 = (PyObject*)__Pyx_PyCode_New(0, 0, 0, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_cryptz_py, __pyx_n_s_banner, 49, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__39)) __PYX_ERR(0, 49, __pyx_L1_error)

  /* "cryptz.py":59
 *     print(unknown15 + "  made by: " + Red + "Do0pH2ck and inc0gnit0\n" + Reset)
 *     print(unknown15 + "  Instagram: " + Red +"benelhaj_younes(Do0pH2ck) i.nc0gnit0(inc0gnit0)\n" + Reset)
 * def main():             # <<<<<<<<<<<<<<
 *     for i in range(1):
 *         banner()
 */
  __pyx_tuple__40 = PyTuple_Pack(19, __pyx_n_s_i, __pyx_n_s_password, __pyx_n_s_db, __pyx_n_s_connect1, __pyx_n_s_catch_pass, __pyx_n_s_result, __pyx_n_s_strings, __pyx_n_s_reverse_char, __pyx_n_s_reverse_char, __pyx_n_s_unreversed_char, __pyx_n_s_unreversed_char, __pyx_n_s_add_string, __pyx_n_s_add_string, __pyx_n_s_rem_string, __pyx_n_s_rem_string, __pyx_n_s_choice, __pyx_n_s_data, __pyx_n_s_encode1, __pyx_n_s_dec); if (unlikely(!__pyx_tuple__40)) __PYX_ERR(0, 59, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__40);
  __Pyx_GIVEREF(__pyx_tuple__40);
  __pyx_codeobj__41 = (PyObject*)__Pyx_PyCode_New(0, 0, 19, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__40, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_cryptz_py, __pyx_n_s_main_2, 59, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__41)) __PYX_ERR(0, 59, __pyx_L1_error)
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitGlobals(void) {
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  __pyx_float_0_10 = PyFloat_FromDouble(0.10); if (unlikely(!__pyx_float_0_10)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_1 = PyInt_FromLong(1); if (unlikely(!__pyx_int_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_3 = PyInt_FromLong(3); if (unlikely(!__pyx_int_3)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_5 = PyInt_FromLong(5); if (unlikely(!__pyx_int_5)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_neg_1 = PyInt_FromLong(-1); if (unlikely(!__pyx_int_neg_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_modinit_global_init_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_export_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_function_export_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_type_init_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_type_import_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_import_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_function_import_code(void); /*proto*/

static int __Pyx_modinit_global_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_global_init_code", 0);
  /*--- Global init code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_export_code", 0);
  /*--- Variable export code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_export_code", 0);
  /*--- Function export code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_type_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_init_code", 0);
  /*--- Type init code ---*/
  if (PyType_Ready(&__pyx_type_6cryptz___pyx_scope_struct__main) < 0) __PYX_ERR(0, 59, __pyx_L1_error)
  #if PY_VERSION_HEX < 0x030800B1
  __pyx_type_6cryptz___pyx_scope_struct__main.tp_print = 0;
  #endif
  if ((CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP) && likely(!__pyx_type_6cryptz___pyx_scope_struct__main.tp_dictoffset && __pyx_type_6cryptz___pyx_scope_struct__main.tp_getattro == PyObject_GenericGetAttr)) {
    __pyx_type_6cryptz___pyx_scope_struct__main.tp_getattro = __Pyx_PyObject_GenericGetAttrNoDict;
  }
  __pyx_ptype_6cryptz___pyx_scope_struct__main = &__pyx_type_6cryptz___pyx_scope_struct__main;
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static int __Pyx_modinit_type_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_import_code", 0);
  /*--- Type import code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_import_code", 0);
  /*--- Variable import code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_import_code", 0);
  /*--- Function import code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}


#if PY_MAJOR_VERSION < 3
#ifdef CYTHON_NO_PYINIT_EXPORT
#define __Pyx_PyMODINIT_FUNC void
#else
#define __Pyx_PyMODINIT_FUNC PyMODINIT_FUNC
#endif
#else
#ifdef CYTHON_NO_PYINIT_EXPORT
#define __Pyx_PyMODINIT_FUNC PyObject *
#else
#define __Pyx_PyMODINIT_FUNC PyMODINIT_FUNC
#endif
#endif


#if PY_MAJOR_VERSION < 3
__Pyx_PyMODINIT_FUNC initcryptz(void) CYTHON_SMALL_CODE; /*proto*/
__Pyx_PyMODINIT_FUNC initcryptz(void)
#else
__Pyx_PyMODINIT_FUNC PyInit_cryptz(void) CYTHON_SMALL_CODE; /*proto*/
__Pyx_PyMODINIT_FUNC PyInit_cryptz(void)
#if CYTHON_PEP489_MULTI_PHASE_INIT
{
  return PyModuleDef_Init(&__pyx_moduledef);
}
static CYTHON_SMALL_CODE int __Pyx_check_single_interpreter(void) {
    #if PY_VERSION_HEX >= 0x030700A1
    static PY_INT64_T main_interpreter_id = -1;
    PY_INT64_T current_id = PyInterpreterState_GetID(PyThreadState_Get()->interp);
    if (main_interpreter_id == -1) {
        main_interpreter_id = current_id;
        return (unlikely(current_id == -1)) ? -1 : 0;
    } else if (unlikely(main_interpreter_id != current_id))
    #else
    static PyInterpreterState *main_interpreter = NULL;
    PyInterpreterState *current_interpreter = PyThreadState_Get()->interp;
    if (!main_interpreter) {
        main_interpreter = current_interpreter;
    } else if (unlikely(main_interpreter != current_interpreter))
    #endif
    {
        PyErr_SetString(
            PyExc_ImportError,
            "Interpreter change detected - this module can only be loaded into one interpreter per process.");
        return -1;
    }
    return 0;
}
static CYTHON_SMALL_CODE int __Pyx_copy_spec_to_module(PyObject *spec, PyObject *moddict, const char* from_name, const char* to_name, int allow_none) {
    PyObject *value = PyObject_GetAttrString(spec, from_name);
    int result = 0;
    if (likely(value)) {
        if (allow_none || value != Py_None) {
            result = PyDict_SetItemString(moddict, to_name, value);
        }
        Py_DECREF(value);
    } else if (PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Clear();
    } else {
        result = -1;
    }
    return result;
}
static CYTHON_SMALL_CODE PyObject* __pyx_pymod_create(PyObject *spec, CYTHON_UNUSED PyModuleDef *def) {
    PyObject *module = NULL, *moddict, *modname;
    if (__Pyx_check_single_interpreter())
        return NULL;
    if (__pyx_m)
        return __Pyx_NewRef(__pyx_m);
    modname = PyObject_GetAttrString(spec, "name");
    if (unlikely(!modname)) goto bad;
    module = PyModule_NewObject(modname);
    Py_DECREF(modname);
    if (unlikely(!module)) goto bad;
    moddict = PyModule_GetDict(module);
    if (unlikely(!moddict)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "loader", "__loader__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "origin", "__file__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "parent", "__package__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "submodule_search_locations", "__path__", 0) < 0)) goto bad;
    return module;
bad:
    Py_XDECREF(module);
    return NULL;
}


static CYTHON_SMALL_CODE int __pyx_pymod_exec_cryptz(PyObject *__pyx_pyinit_module)
#endif
#endif
{
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  PyObject *__pyx_t_5 = NULL;
  int __pyx_t_6;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  PyObject *__pyx_t_9 = NULL;
  int __pyx_t_10;
  __Pyx_RefNannyDeclarations
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  if (__pyx_m) {
    if (__pyx_m == __pyx_pyinit_module) return 0;
    PyErr_SetString(PyExc_RuntimeError, "Module 'cryptz' has already been imported. Re-initialisation is not supported.");
    return -1;
  }
  #elif PY_MAJOR_VERSION >= 3
  if (__pyx_m) return __Pyx_NewRef(__pyx_m);
  #endif
  #if CYTHON_REFNANNY
__Pyx_RefNanny = __Pyx_RefNannyImportAPI("refnanny");
if (!__Pyx_RefNanny) {
  PyErr_Clear();
  __Pyx_RefNanny = __Pyx_RefNannyImportAPI("Cython.Runtime.refnanny");
  if (!__Pyx_RefNanny)
      Py_FatalError("failed to import 'refnanny' module");
}
#endif
  __Pyx_RefNannySetupContext("__Pyx_PyMODINIT_FUNC PyInit_cryptz(void)", 0);
  if (__Pyx_check_binary_version() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pxy_PyFrame_Initialize_Offsets
  __Pxy_PyFrame_Initialize_Offsets();
  #endif
  __pyx_empty_tuple = PyTuple_New(0); if (unlikely(!__pyx_empty_tuple)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_bytes = PyBytes_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_bytes)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_unicode = PyUnicode_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_unicode)) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pyx_CyFunction_USED
  if (__pyx_CyFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_FusedFunction_USED
  if (__pyx_FusedFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Coroutine_USED
  if (__pyx_Coroutine_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Generator_USED
  if (__pyx_Generator_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_AsyncGen_USED
  if (__pyx_AsyncGen_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_StopAsyncIteration_USED
  if (__pyx_StopAsyncIteration_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  /*--- Library function declarations ---*/
  /*--- Threads initialization code ---*/
  #if defined(__PYX_FORCE_INIT_THREADS) && __PYX_FORCE_INIT_THREADS
  #ifdef WITH_THREAD /* Python build with threading support? */
  PyEval_InitThreads();
  #endif
  #endif
  /*--- Module creation code ---*/
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  __pyx_m = __pyx_pyinit_module;
  Py_INCREF(__pyx_m);
  #else
  #if PY_MAJOR_VERSION < 3
  __pyx_m = Py_InitModule4("cryptz", __pyx_methods, 0, 0, PYTHON_API_VERSION); Py_XINCREF(__pyx_m);
  #else
  __pyx_m = PyModule_Create(&__pyx_moduledef);
  #endif
  if (unlikely(!__pyx_m)) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  __pyx_d = PyModule_GetDict(__pyx_m); if (unlikely(!__pyx_d)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_d);
  __pyx_b = PyImport_AddModule(__Pyx_BUILTIN_MODULE_NAME); if (unlikely(!__pyx_b)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_b);
  __pyx_cython_runtime = PyImport_AddModule((char *) "cython_runtime"); if (unlikely(!__pyx_cython_runtime)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_cython_runtime);
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  /*--- Initialize various global constants etc. ---*/
  if (__Pyx_InitGlobals() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #if PY_MAJOR_VERSION < 3 && (__PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT)
  if (__Pyx_init_sys_getdefaultencoding_params() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  if (__pyx_module_is_main_cryptz) {
    if (PyObject_SetAttr(__pyx_m, __pyx_n_s_name, __pyx_n_s_main) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  }
  #if PY_MAJOR_VERSION >= 3
  {
    PyObject *modules = PyImport_GetModuleDict(); if (unlikely(!modules)) __PYX_ERR(0, 1, __pyx_L1_error)
    if (!PyDict_GetItemString(modules, "cryptz")) {
      if (unlikely(PyDict_SetItemString(modules, "cryptz", __pyx_m) < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
    }
  }
  #endif
  /*--- Builtin init code ---*/
  if (__Pyx_InitCachedBuiltins() < 0) goto __pyx_L1_error;
  /*--- Constants init code ---*/
  if (__Pyx_InitCachedConstants() < 0) goto __pyx_L1_error;
  /*--- Global type/function init code ---*/
  (void)__Pyx_modinit_global_init_code();
  (void)__Pyx_modinit_variable_export_code();
  (void)__Pyx_modinit_function_export_code();
  if (unlikely(__Pyx_modinit_type_init_code() != 0)) goto __pyx_L1_error;
  (void)__Pyx_modinit_type_import_code();
  (void)__Pyx_modinit_variable_import_code();
  (void)__Pyx_modinit_function_import_code();
  /*--- Execution code ---*/
  #if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
  if (__Pyx_patch_abc() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif

  /* "cryptz.py":5
 * # CopyRight , All rights Received (GNU Rights)
 * # Don't Copy The Code Without Giving Me The Credits Nerds !!!
 * try:             # <<<<<<<<<<<<<<
 *     import pybase64,sqlite3,re,os,sys
 *     import datetime
 */
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_1, &__pyx_t_2, &__pyx_t_3);
    __Pyx_XGOTREF(__pyx_t_1);
    __Pyx_XGOTREF(__pyx_t_2);
    __Pyx_XGOTREF(__pyx_t_3);
    /*try:*/ {

      /* "cryptz.py":6
 * # Don't Copy The Code Without Giving Me The Credits Nerds !!!
 * try:
 *     import pybase64,sqlite3,re,os,sys             # <<<<<<<<<<<<<<
 *     import datetime
 *     from time import sleep as sl
 */
      __pyx_t_4 = __Pyx_Import(__pyx_n_s_pybase64, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 6, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_4);
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_pybase64, __pyx_t_4) < 0) __PYX_ERR(0, 6, __pyx_L2_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_4 = __Pyx_Import(__pyx_n_s_sqlite3, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 6, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_4);
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_sqlite3, __pyx_t_4) < 0) __PYX_ERR(0, 6, __pyx_L2_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_4 = __Pyx_Import(__pyx_n_s_re, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 6, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_4);
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_re, __pyx_t_4) < 0) __PYX_ERR(0, 6, __pyx_L2_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_4 = __Pyx_Import(__pyx_n_s_os, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 6, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_4);
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_os, __pyx_t_4) < 0) __PYX_ERR(0, 6, __pyx_L2_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_4 = __Pyx_Import(__pyx_n_s_sys, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 6, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_4);
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_sys, __pyx_t_4) < 0) __PYX_ERR(0, 6, __pyx_L2_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

      /* "cryptz.py":7
 * try:
 *     import pybase64,sqlite3,re,os,sys
 *     import datetime             # <<<<<<<<<<<<<<
 *     from time import sleep as sl
 * except ImportError:
 */
      __pyx_t_4 = __Pyx_Import(__pyx_n_s_datetime, 0, 0); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 7, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_4);
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_datetime, __pyx_t_4) < 0) __PYX_ERR(0, 7, __pyx_L2_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

      /* "cryptz.py":8
 *     import pybase64,sqlite3,re,os,sys
 *     import datetime
 *     from time import sleep as sl             # <<<<<<<<<<<<<<
 * except ImportError:
 *         print("\033[31m" + "Please run: python3 install.py" + "\033[0m")
 */
      __pyx_t_4 = PyList_New(1); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 8, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_INCREF(__pyx_n_s_sleep);
      __Pyx_GIVEREF(__pyx_n_s_sleep);
      PyList_SET_ITEM(__pyx_t_4, 0, __pyx_n_s_sleep);
      __pyx_t_5 = __Pyx_Import(__pyx_n_s_time, __pyx_t_4, 0); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 8, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_4 = __Pyx_ImportFrom(__pyx_t_5, __pyx_n_s_sleep); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 8, __pyx_L2_error)
      __Pyx_GOTREF(__pyx_t_4);
      if (PyDict_SetItem(__pyx_d, __pyx_n_s_sl, __pyx_t_4) < 0) __PYX_ERR(0, 8, __pyx_L2_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

      /* "cryptz.py":5
 * # CopyRight , All rights Received (GNU Rights)
 * # Don't Copy The Code Without Giving Me The Credits Nerds !!!
 * try:             # <<<<<<<<<<<<<<
 *     import pybase64,sqlite3,re,os,sys
 *     import datetime
 */
    }
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    goto __pyx_L7_try_end;
    __pyx_L2_error:;
    __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
    __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;

    /* "cryptz.py":9
 *     import datetime
 *     from time import sleep as sl
 * except ImportError:             # <<<<<<<<<<<<<<
 *         print("\033[31m" + "Please run: python3 install.py" + "\033[0m")
 *         exit(1)
 */
    __pyx_t_6 = __Pyx_PyErr_ExceptionMatches(__pyx_builtin_ImportError);
    if (__pyx_t_6) {
      __Pyx_AddTraceback("cryptz", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_5, &__pyx_t_4, &__pyx_t_7) < 0) __PYX_ERR(0, 9, __pyx_L4_except_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_GOTREF(__pyx_t_7);

      /* "cryptz.py":10
 *     from time import sleep as sl
 * except ImportError:
 *         print("\033[31m" + "Please run: python3 install.py" + "\033[0m")             # <<<<<<<<<<<<<<
 *         exit(1)
 * def clear():
 */
      __pyx_t_8 = __Pyx_PyObject_Call(__pyx_builtin_print, __pyx_tuple__36, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 10, __pyx_L4_except_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

      /* "cryptz.py":11
 * except ImportError:
 *         print("\033[31m" + "Please run: python3 install.py" + "\033[0m")
 *         exit(1)             # <<<<<<<<<<<<<<
 * def clear():
 *     os.system('clear || cls')
 */
      __pyx_t_8 = __Pyx_PyObject_Call(__pyx_builtin_exit, __pyx_tuple__34, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 11, __pyx_L4_except_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_XDECREF(__pyx_t_4); __pyx_t_4 = 0;
      __Pyx_XDECREF(__pyx_t_7); __pyx_t_7 = 0;
      goto __pyx_L3_exception_handled;
    }
    goto __pyx_L4_except_error;
    __pyx_L4_except_error:;

    /* "cryptz.py":5
 * # CopyRight , All rights Received (GNU Rights)
 * # Don't Copy The Code Without Giving Me The Credits Nerds !!!
 * try:             # <<<<<<<<<<<<<<
 *     import pybase64,sqlite3,re,os,sys
 *     import datetime
 */
    __Pyx_XGIVEREF(__pyx_t_1);
    __Pyx_XGIVEREF(__pyx_t_2);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_1, __pyx_t_2, __pyx_t_3);
    goto __pyx_L1_error;
    __pyx_L3_exception_handled:;
    __Pyx_XGIVEREF(__pyx_t_1);
    __Pyx_XGIVEREF(__pyx_t_2);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_1, __pyx_t_2, __pyx_t_3);
    __pyx_L7_try_end:;
  }

  /* "cryptz.py":12
 *         print("\033[31m" + "Please run: python3 install.py" + "\033[0m")
 *         exit(1)
 * def clear():             # <<<<<<<<<<<<<<
 *     os.system('clear || cls')
 * 
 */
  __pyx_t_7 = __Pyx_CyFunction_NewEx(&__pyx_mdef_6cryptz_1clear, 0, __pyx_n_s_clear, NULL, __pyx_n_s_cryptz, __pyx_d, ((PyObject *)__pyx_codeobj__37)); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_clear, __pyx_t_7) < 0) __PYX_ERR(0, 12, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

  /* "cryptz.py":15
 *     os.system('clear || cls')
 * 
 * clear()             # <<<<<<<<<<<<<<
 * ## Set Date ####
 * now = datetime.datetime.now()
 */
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_clear); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_4 = __Pyx_PyObject_CallNoArg(__pyx_t_7); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 15, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "cryptz.py":17
 * clear()
 * ## Set Date ####
 * now = datetime.datetime.now()             # <<<<<<<<<<<<<<
 * hour = now.hour
 * min = now.minute
 */
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_datetime); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_datetime); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_now); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  __pyx_t_7 = __Pyx_PyObject_CallNoArg(__pyx_t_4); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_now, __pyx_t_7) < 0) __PYX_ERR(0, 17, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

  /* "cryptz.py":18
 * ## Set Date ####
 * now = datetime.datetime.now()
 * hour = now.hour             # <<<<<<<<<<<<<<
 * min = now.minute
 * sec = now.second
 */
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_now); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 18, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_hour); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 18, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_hour, __pyx_t_4) < 0) __PYX_ERR(0, 18, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "cryptz.py":19
 * now = datetime.datetime.now()
 * hour = now.hour
 * min = now.minute             # <<<<<<<<<<<<<<
 * sec = now.second
 * timenow = "{}:{}:{}".format(hour,min,sec)
 */
  __Pyx_GetModuleGlobalName(__pyx_t_4, __pyx_n_s_now); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 19, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __pyx_t_7 = __Pyx_PyObject_GetAttrStr(__pyx_t_4, __pyx_n_s_minute); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 19, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_min, __pyx_t_7) < 0) __PYX_ERR(0, 19, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;

  /* "cryptz.py":20
 * hour = now.hour
 * min = now.minute
 * sec = now.second             # <<<<<<<<<<<<<<
 * timenow = "{}:{}:{}".format(hour,min,sec)
 * #######Colors###########
 */
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_now); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_t_7, __pyx_n_s_second); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_DECREF(__pyx_t_7); __pyx_t_7 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_sec, __pyx_t_4) < 0) __PYX_ERR(0, 20, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;

  /* "cryptz.py":21
 * min = now.minute
 * sec = now.second
 * timenow = "{}:{}:{}".format(hour,min,sec)             # <<<<<<<<<<<<<<
 * #######Colors###########
 * Green="\033[1;33m"
 */
  __pyx_t_4 = __Pyx_PyObject_GetAttrStr(__pyx_kp_u__38, __pyx_n_s_format); if (unlikely(!__pyx_t_4)) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_4);
  __Pyx_GetModuleGlobalName(__pyx_t_7, __pyx_n_s_hour); if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_7);
  __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_min); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_sec); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_9 = PyTuple_New(3); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  __Pyx_GIVEREF(__pyx_t_7);
  PyTuple_SET_ITEM(__pyx_t_9, 0, __pyx_t_7);
  __Pyx_GIVEREF(__pyx_t_5);
  PyTuple_SET_ITEM(__pyx_t_9, 1, __pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_8);
  PyTuple_SET_ITEM(__pyx_t_9, 2, __pyx_t_8);
  __pyx_t_7 = 0;
  __pyx_t_5 = 0;
  __pyx_t_8 = 0;
  __pyx_t_8 = __Pyx_PyObject_Call(__pyx_t_4, __pyx_t_9, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_timenow, __pyx_t_8) < 0) __PYX_ERR(0, 21, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  /* "cryptz.py":23
 * timenow = "{}:{}:{}".format(hour,min,sec)
 * #######Colors###########
 * Green="\033[1;33m"             # <<<<<<<<<<<<<<
 * Blue="\033[1;34m"
 * Grey="\033[1;30m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Green, __pyx_kp_u_1_33m) < 0) __PYX_ERR(0, 23, __pyx_L1_error)

  /* "cryptz.py":24
 * #######Colors###########
 * Green="\033[1;33m"
 * Blue="\033[1;34m"             # <<<<<<<<<<<<<<
 * Grey="\033[1;30m"
 * Reset="\033[0m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Blue, __pyx_kp_u_1_34m) < 0) __PYX_ERR(0, 24, __pyx_L1_error)

  /* "cryptz.py":25
 * Green="\033[1;33m"
 * Blue="\033[1;34m"
 * Grey="\033[1;30m"             # <<<<<<<<<<<<<<
 * Reset="\033[0m"
 * yellow="\033[1;36m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Grey, __pyx_kp_u_1_30m) < 0) __PYX_ERR(0, 25, __pyx_L1_error)

  /* "cryptz.py":26
 * Blue="\033[1;34m"
 * Grey="\033[1;30m"
 * Reset="\033[0m"             # <<<<<<<<<<<<<<
 * yellow="\033[1;36m"
 * Red="\033[1;31m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Reset, __pyx_kp_u_0m_2) < 0) __PYX_ERR(0, 26, __pyx_L1_error)

  /* "cryptz.py":27
 * Grey="\033[1;30m"
 * Reset="\033[0m"
 * yellow="\033[1;36m"             # <<<<<<<<<<<<<<
 * Red="\033[1;31m"
 * purple="\033[35m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_yellow, __pyx_kp_u_1_36m) < 0) __PYX_ERR(0, 27, __pyx_L1_error)

  /* "cryptz.py":28
 * Reset="\033[0m"
 * yellow="\033[1;36m"
 * Red="\033[1;31m"             # <<<<<<<<<<<<<<
 * purple="\033[35m"
 * Light="\033[95m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Red, __pyx_kp_u_1_31m) < 0) __PYX_ERR(0, 28, __pyx_L1_error)

  /* "cryptz.py":29
 * yellow="\033[1;36m"
 * Red="\033[1;31m"
 * purple="\033[35m"             # <<<<<<<<<<<<<<
 * Light="\033[95m"
 * cyan="\033[96m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_purple, __pyx_kp_u_35m) < 0) __PYX_ERR(0, 29, __pyx_L1_error)

  /* "cryptz.py":30
 * Red="\033[1;31m"
 * purple="\033[35m"
 * Light="\033[95m"             # <<<<<<<<<<<<<<
 * cyan="\033[96m"
 * stong="\033[39m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_Light, __pyx_kp_u_95m) < 0) __PYX_ERR(0, 30, __pyx_L1_error)

  /* "cryptz.py":31
 * purple="\033[35m"
 * Light="\033[95m"
 * cyan="\033[96m"             # <<<<<<<<<<<<<<
 * stong="\033[39m"
 * unknown="\033[38;5;82m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_cyan, __pyx_kp_u_96m) < 0) __PYX_ERR(0, 31, __pyx_L1_error)

  /* "cryptz.py":32
 * Light="\033[95m"
 * cyan="\033[96m"
 * stong="\033[39m"             # <<<<<<<<<<<<<<
 * unknown="\033[38;5;82m"
 * unknown2="\033[38;5;198m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_stong, __pyx_kp_u_39m) < 0) __PYX_ERR(0, 32, __pyx_L1_error)

  /* "cryptz.py":33
 * cyan="\033[96m"
 * stong="\033[39m"
 * unknown="\033[38;5;82m"             # <<<<<<<<<<<<<<
 * unknown2="\033[38;5;198m"
 * unknown3="\033[38;5;208m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown, __pyx_kp_u_38_5_82m) < 0) __PYX_ERR(0, 33, __pyx_L1_error)

  /* "cryptz.py":34
 * stong="\033[39m"
 * unknown="\033[38;5;82m"
 * unknown2="\033[38;5;198m"             # <<<<<<<<<<<<<<
 * unknown3="\033[38;5;208m"
 * unknown4="\033[38;5;167m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown2, __pyx_kp_u_38_5_198m) < 0) __PYX_ERR(0, 34, __pyx_L1_error)

  /* "cryptz.py":35
 * unknown="\033[38;5;82m"
 * unknown2="\033[38;5;198m"
 * unknown3="\033[38;5;208m"             # <<<<<<<<<<<<<<
 * unknown4="\033[38;5;167m"
 * unknown5="\033[38;5;91m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown3, __pyx_kp_u_38_5_208m) < 0) __PYX_ERR(0, 35, __pyx_L1_error)

  /* "cryptz.py":36
 * unknown2="\033[38;5;198m"
 * unknown3="\033[38;5;208m"
 * unknown4="\033[38;5;167m"             # <<<<<<<<<<<<<<
 * unknown5="\033[38;5;91m"
 * unknown6="\033[38;5;210m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown4, __pyx_kp_u_38_5_167m) < 0) __PYX_ERR(0, 36, __pyx_L1_error)

  /* "cryptz.py":37
 * unknown3="\033[38;5;208m"
 * unknown4="\033[38;5;167m"
 * unknown5="\033[38;5;91m"             # <<<<<<<<<<<<<<
 * unknown6="\033[38;5;210m"
 * unknown7="\033[38;5;165m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown5, __pyx_kp_u_38_5_91m) < 0) __PYX_ERR(0, 37, __pyx_L1_error)

  /* "cryptz.py":38
 * unknown4="\033[38;5;167m"
 * unknown5="\033[38;5;91m"
 * unknown6="\033[38;5;210m"             # <<<<<<<<<<<<<<
 * unknown7="\033[38;5;165m"
 * unknown8="\033[38;5;49m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown6, __pyx_kp_u_38_5_210m) < 0) __PYX_ERR(0, 38, __pyx_L1_error)

  /* "cryptz.py":39
 * unknown5="\033[38;5;91m"
 * unknown6="\033[38;5;210m"
 * unknown7="\033[38;5;165m"             # <<<<<<<<<<<<<<
 * unknown8="\033[38;5;49m"
 * unknown9="\033[38;5;160m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown7, __pyx_kp_u_38_5_165m) < 0) __PYX_ERR(0, 39, __pyx_L1_error)

  /* "cryptz.py":40
 * unknown6="\033[38;5;210m"
 * unknown7="\033[38;5;165m"
 * unknown8="\033[38;5;49m"             # <<<<<<<<<<<<<<
 * unknown9="\033[38;5;160m"
 * unknown10="\033[38;5;51m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown8, __pyx_kp_u_38_5_49m) < 0) __PYX_ERR(0, 40, __pyx_L1_error)

  /* "cryptz.py":41
 * unknown7="\033[38;5;165m"
 * unknown8="\033[38;5;49m"
 * unknown9="\033[38;5;160m"             # <<<<<<<<<<<<<<
 * unknown10="\033[38;5;51m"
 * unknown11="\033[38;5;13m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown9, __pyx_kp_u_38_5_160m) < 0) __PYX_ERR(0, 41, __pyx_L1_error)

  /* "cryptz.py":42
 * unknown8="\033[38;5;49m"
 * unknown9="\033[38;5;160m"
 * unknown10="\033[38;5;51m"             # <<<<<<<<<<<<<<
 * unknown11="\033[38;5;13m"
 * unknown12="\033[38;5;162m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown10, __pyx_kp_u_38_5_51m) < 0) __PYX_ERR(0, 42, __pyx_L1_error)

  /* "cryptz.py":43
 * unknown9="\033[38;5;160m"
 * unknown10="\033[38;5;51m"
 * unknown11="\033[38;5;13m"             # <<<<<<<<<<<<<<
 * unknown12="\033[38;5;162m"
 * unknown13="\033[38;5;203m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown11, __pyx_kp_u_38_5_13m) < 0) __PYX_ERR(0, 43, __pyx_L1_error)

  /* "cryptz.py":44
 * unknown10="\033[38;5;51m"
 * unknown11="\033[38;5;13m"
 * unknown12="\033[38;5;162m"             # <<<<<<<<<<<<<<
 * unknown13="\033[38;5;203m"
 * unknown14="\033[38;5;113m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown12, __pyx_kp_u_38_5_162m) < 0) __PYX_ERR(0, 44, __pyx_L1_error)

  /* "cryptz.py":45
 * unknown11="\033[38;5;13m"
 * unknown12="\033[38;5;162m"
 * unknown13="\033[38;5;203m"             # <<<<<<<<<<<<<<
 * unknown14="\033[38;5;113m"
 * unknown15="\033[38;5;14m"
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown13, __pyx_kp_u_38_5_203m) < 0) __PYX_ERR(0, 45, __pyx_L1_error)

  /* "cryptz.py":46
 * unknown12="\033[38;5;162m"
 * unknown13="\033[38;5;203m"
 * unknown14="\033[38;5;113m"             # <<<<<<<<<<<<<<
 * unknown15="\033[38;5;14m"
 * ##########################
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown14, __pyx_kp_u_38_5_113m) < 0) __PYX_ERR(0, 46, __pyx_L1_error)

  /* "cryptz.py":47
 * unknown13="\033[38;5;203m"
 * unknown14="\033[38;5;113m"
 * unknown15="\033[38;5;14m"             # <<<<<<<<<<<<<<
 * ##########################
 * def banner():
 */
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_unknown15, __pyx_kp_u_38_5_14m) < 0) __PYX_ERR(0, 47, __pyx_L1_error)

  /* "cryptz.py":49
 * unknown15="\033[38;5;14m"
 * ##########################
 * def banner():             # <<<<<<<<<<<<<<
 *     print(unknown2 + "\n  https://github.com/doophack/cryptz\n")
 *     print(unknown15 + "   ####   #####   #   #  #####   #####  ###### ")
 */
  __pyx_t_8 = __Pyx_CyFunction_NewEx(&__pyx_mdef_6cryptz_3banner, 0, __pyx_n_s_banner, NULL, __pyx_n_s_cryptz, __pyx_d, ((PyObject *)__pyx_codeobj__39)); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 49, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_banner, __pyx_t_8) < 0) __PYX_ERR(0, 49, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  /* "cryptz.py":59
 *     print(unknown15 + "  made by: " + Red + "Do0pH2ck and inc0gnit0\n" + Reset)
 *     print(unknown15 + "  Instagram: " + Red +"benelhaj_younes(Do0pH2ck) i.nc0gnit0(inc0gnit0)\n" + Reset)
 * def main():             # <<<<<<<<<<<<<<
 *     for i in range(1):
 *         banner()
 */
  __pyx_t_8 = __Pyx_CyFunction_NewEx(&__pyx_mdef_6cryptz_5main, 0, __pyx_n_s_main_2, NULL, __pyx_n_s_cryptz, __pyx_d, ((PyObject *)__pyx_codeobj__41)); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 59, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_main_2, __pyx_t_8) < 0) __PYX_ERR(0, 59, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;

  /* "cryptz.py":152
 *             print("  Unauthorized Access !!\n  Warning Don't Try Random Things Or You'll Be Banned!!\n  To get a License Key you will need to contact creators for one")
 *             exit(1)
 * if __name__ == '__main__':             # <<<<<<<<<<<<<<
 *     main()
 */
  __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_name); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_8);
  __pyx_t_10 = (__Pyx_PyUnicode_Equals(__pyx_t_8, __pyx_n_u_main, Py_EQ)); if (unlikely(__pyx_t_10 < 0)) __PYX_ERR(0, 152, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
  if (__pyx_t_10) {

    /* "cryptz.py":153
 *             exit(1)
 * if __name__ == '__main__':
 *     main()             # <<<<<<<<<<<<<<
 */
    __Pyx_GetModuleGlobalName(__pyx_t_8, __pyx_n_s_main_2); if (unlikely(!__pyx_t_8)) __PYX_ERR(0, 153, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_8);
    __pyx_t_9 = __Pyx_PyObject_CallNoArg(__pyx_t_8); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 153, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_9);
    __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
    __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

    /* "cryptz.py":152
 *             print("  Unauthorized Access !!\n  Warning Don't Try Random Things Or You'll Be Banned!!\n  To get a License Key you will need to contact creators for one")
 *             exit(1)
 * if __name__ == '__main__':             # <<<<<<<<<<<<<<
 *     main()
 */
  }

  /* "cryptz.py":1
 * #!/usr/bin/env python3             # <<<<<<<<<<<<<<
 * # Created By benelhaj_younes(Do0pH2ck) and i.nc0gnt0(inc0gnit0)
 * # CopyRight , All rights Received (GNU Rights)
 */
  __pyx_t_9 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_9)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_9);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_test, __pyx_t_9) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_9); __pyx_t_9 = 0;

  /*--- Wrapped vars code ---*/

  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_XDECREF(__pyx_t_9);
  if (__pyx_m) {
    if (__pyx_d) {
      __Pyx_AddTraceback("init cryptz", __pyx_clineno, __pyx_lineno, __pyx_filename);
    }
    Py_CLEAR(__pyx_m);
  } else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_ImportError, "init cryptz");
  }
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  return (__pyx_m != NULL) ? 0 : -1;
  #elif PY_MAJOR_VERSION >= 3
  return __pyx_m;
  #else
  return;
  #endif
}

/* --- Runtime support code --- */
/* Refnanny */
#if CYTHON_REFNANNY
static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname) {
    PyObject *m = NULL, *p = NULL;
    void *r = NULL;
    m = PyImport_ImportModule(modname);
    if (!m) goto end;
    p = PyObject_GetAttrString(m, "RefNannyAPI");
    if (!p) goto end;
    r = PyLong_AsVoidPtr(p);
end:
    Py_XDECREF(p);
    Py_XDECREF(m);
    return (__Pyx_RefNannyAPIStruct *)r;
}
#endif

/* PyObjectGetAttrStr */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_getattro))
        return tp->tp_getattro(obj, attr_name);
#if PY_MAJOR_VERSION < 3
    if (likely(tp->tp_getattr))
        return tp->tp_getattr(obj, PyString_AS_STRING(attr_name));
#endif
    return PyObject_GetAttr(obj, attr_name);
}
#endif

/* GetBuiltinName */
static PyObject *__Pyx_GetBuiltinName(PyObject *name) {
    PyObject* result = __Pyx_PyObject_GetAttrStr(__pyx_b, name);
    if (unlikely(!result)) {
        PyErr_Format(PyExc_NameError,
#if PY_MAJOR_VERSION >= 3
            "name '%U' is not defined", name);
#else
            "name '%.200s' is not defined", PyString_AS_STRING(name));
#endif
    }
    return result;
}

/* PyDictVersioning */
#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    return likely(dict) ? __PYX_GET_DICT_VERSION(dict) : 0;
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj) {
    PyObject **dictptr = NULL;
    Py_ssize_t offset = Py_TYPE(obj)->tp_dictoffset;
    if (offset) {
#if CYTHON_COMPILING_IN_CPYTHON
        dictptr = (likely(offset > 0)) ? (PyObject **) ((char *)obj + offset) : _PyObject_GetDictPtr(obj);
#else
        dictptr = _PyObject_GetDictPtr(obj);
#endif
    }
    return (dictptr && *dictptr) ? __PYX_GET_DICT_VERSION(*dictptr) : 0;
}
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    if (unlikely(!dict) || unlikely(tp_dict_version != __PYX_GET_DICT_VERSION(dict)))
        return 0;
    return obj_dict_version == __Pyx_get_object_dict_version(obj);
}
#endif

/* GetModuleGlobalName */
#if CYTHON_USE_DICT_VERSIONS
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value)
#else
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name)
#endif
{
    PyObject *result;
#if !CYTHON_AVOID_BORROWED_REFS
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1
    result = _PyDict_GetItem_KnownHash(__pyx_d, name, ((PyASCIIObject *) name)->hash);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    } else if (unlikely(PyErr_Occurred())) {
        return NULL;
    }
#else
    result = PyDict_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
#endif
#else
    result = PyObject_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
    PyErr_Clear();
#endif
    return __Pyx_GetBuiltinName(name);
}

/* PyCFunctionFastCall */
#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject * __Pyx_PyCFunction_FastCall(PyObject *func_obj, PyObject **args, Py_ssize_t nargs) {
    PyCFunctionObject *func = (PyCFunctionObject*)func_obj;
    PyCFunction meth = PyCFunction_GET_FUNCTION(func);
    PyObject *self = PyCFunction_GET_SELF(func);
    int flags = PyCFunction_GET_FLAGS(func);
    assert(PyCFunction_Check(func));
    assert(METH_FASTCALL == (flags & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)));
    assert(nargs >= 0);
    assert(nargs == 0 || args != NULL);
    /* _PyCFunction_FastCallDict() must not be called with an exception set,
       because it may clear it (directly or indirectly) and so the
       caller loses its exception */
    assert(!PyErr_Occurred());
    if ((PY_VERSION_HEX < 0x030700A0) || unlikely(flags & METH_KEYWORDS)) {
        return (*((__Pyx_PyCFunctionFastWithKeywords)(void*)meth)) (self, args, nargs, NULL);
    } else {
        return (*((__Pyx_PyCFunctionFast)(void*)meth)) (self, args, nargs);
    }
}
#endif

/* PyFunctionFastCall */
#if CYTHON_FAST_PYCALL
static PyObject* __Pyx_PyFunction_FastCallNoKw(PyCodeObject *co, PyObject **args, Py_ssize_t na,
                                               PyObject *globals) {
    PyFrameObject *f;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject **fastlocals;
    Py_ssize_t i;
    PyObject *result;
    assert(globals != NULL);
    /* XXX Perhaps we should create a specialized
       PyFrame_New() that doesn't take locals, but does
       take builtins without sanity checking them.
       */
    assert(tstate != NULL);
    f = PyFrame_New(tstate, co, globals, NULL);
    if (f == NULL) {
        return NULL;
    }
    fastlocals = __Pyx_PyFrame_GetLocalsplus(f);
    for (i = 0; i < na; i++) {
        Py_INCREF(*args);
        fastlocals[i] = *args++;
    }
    result = PyEval_EvalFrameEx(f,0);
    ++tstate->recursion_depth;
    Py_DECREF(f);
    --tstate->recursion_depth;
    return result;
}
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs) {
    PyCodeObject *co = (PyCodeObject *)PyFunction_GET_CODE(func);
    PyObject *globals = PyFunction_GET_GLOBALS(func);
    PyObject *argdefs = PyFunction_GET_DEFAULTS(func);
    PyObject *closure;
#if PY_MAJOR_VERSION >= 3
    PyObject *kwdefs;
#endif
    PyObject *kwtuple, **k;
    PyObject **d;
    Py_ssize_t nd;
    Py_ssize_t nk;
    PyObject *result;
    assert(kwargs == NULL || PyDict_Check(kwargs));
    nk = kwargs ? PyDict_Size(kwargs) : 0;
    if (Py_EnterRecursiveCall((char*)" while calling a Python object")) {
        return NULL;
    }
    if (
#if PY_MAJOR_VERSION >= 3
            co->co_kwonlyargcount == 0 &&
#endif
            likely(kwargs == NULL || nk == 0) &&
            co->co_flags == (CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE)) {
        if (argdefs == NULL && co->co_argcount == nargs) {
            result = __Pyx_PyFunction_FastCallNoKw(co, args, nargs, globals);
            goto done;
        }
        else if (nargs == 0 && argdefs != NULL
                 && co->co_argcount == Py_SIZE(argdefs)) {
            /* function called with no arguments, but all parameters have
               a default value: use default values as arguments .*/
            args = &PyTuple_GET_ITEM(argdefs, 0);
            result =__Pyx_PyFunction_FastCallNoKw(co, args, Py_SIZE(argdefs), globals);
            goto done;
        }
    }
    if (kwargs != NULL) {
        Py_ssize_t pos, i;
        kwtuple = PyTuple_New(2 * nk);
        if (kwtuple == NULL) {
            result = NULL;
            goto done;
        }
        k = &PyTuple_GET_ITEM(kwtuple, 0);
        pos = i = 0;
        while (PyDict_Next(kwargs, &pos, &k[i], &k[i+1])) {
            Py_INCREF(k[i]);
            Py_INCREF(k[i+1]);
            i += 2;
        }
        nk = i / 2;
    }
    else {
        kwtuple = NULL;
        k = NULL;
    }
    closure = PyFunction_GET_CLOSURE(func);
#if PY_MAJOR_VERSION >= 3
    kwdefs = PyFunction_GET_KW_DEFAULTS(func);
#endif
    if (argdefs != NULL) {
        d = &PyTuple_GET_ITEM(argdefs, 0);
        nd = Py_SIZE(argdefs);
    }
    else {
        d = NULL;
        nd = 0;
    }
#if PY_MAJOR_VERSION >= 3
    result = PyEval_EvalCodeEx((PyObject*)co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, kwdefs, closure);
#else
    result = PyEval_EvalCodeEx(co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, closure);
#endif
    Py_XDECREF(kwtuple);
done:
    Py_LeaveRecursiveCall();
    return result;
}
#endif
#endif

/* PyObjectCall */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    PyObject *result;
    ternaryfunc call = func->ob_type->tp_call;
    if (unlikely(!call))
        return PyObject_Call(func, arg, kw);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = (*call)(func, arg, kw);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif

/* PyObjectCall2Args */
static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2) {
    PyObject *args, *result = NULL;
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyFunction_FastCall(function, args, 2);
    }
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyCFunction_FastCall(function, args, 2);
    }
    #endif
    args = PyTuple_New(2);
    if (unlikely(!args)) goto done;
    Py_INCREF(arg1);
    PyTuple_SET_ITEM(args, 0, arg1);
    Py_INCREF(arg2);
    PyTuple_SET_ITEM(args, 1, arg2);
    Py_INCREF(function);
    result = __Pyx_PyObject_Call(function, args, NULL);
    Py_DECREF(args);
    Py_DECREF(function);
done:
    return result;
}

/* PyObjectCallMethO */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg) {
    PyObject *self, *result;
    PyCFunction cfunc;
    cfunc = PyCFunction_GET_FUNCTION(func);
    self = PyCFunction_GET_SELF(func);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = cfunc(self, arg);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif

/* PyObjectCallOneArg */
#if CYTHON_COMPILING_IN_CPYTHON
static PyObject* __Pyx__PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_New(1);
    if (unlikely(!args)) return NULL;
    Py_INCREF(arg);
    PyTuple_SET_ITEM(args, 0, arg);
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, &arg, 1);
    }
#endif
    if (likely(PyCFunction_Check(func))) {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_O)) {
            return __Pyx_PyObject_CallMethO(func, arg);
#if CYTHON_FAST_PYCCALL
        } else if (PyCFunction_GET_FLAGS(func) & METH_FASTCALL) {
            return __Pyx_PyCFunction_FastCall(func, &arg, 1);
#endif
        }
    }
    return __Pyx__PyObject_CallOneArg(func, arg);
}
#else
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_Pack(1, arg);
    if (unlikely(!args)) return NULL;
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
#endif

/* GetItemInt */
static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j) {
    PyObject *r;
    if (!j) return NULL;
    r = PyObject_GetItem(o, j);
    Py_DECREF(j);
    return r;
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyList_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyList_GET_SIZE(o)))) {
        PyObject *r = PyList_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyTuple_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyTuple_GET_SIZE(o)))) {
        PyObject *r = PyTuple_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i, int is_list,
                                                     CYTHON_NCP_UNUSED int wraparound,
                                                     CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS && CYTHON_USE_TYPE_SLOTS
    if (is_list || PyList_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyList_GET_SIZE(o);
        if ((!boundscheck) || (likely(__Pyx_is_valid_index(n, PyList_GET_SIZE(o))))) {
            PyObject *r = PyList_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    }
    else if (PyTuple_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyTuple_GET_SIZE(o);
        if ((!boundscheck) || likely(__Pyx_is_valid_index(n, PyTuple_GET_SIZE(o)))) {
            PyObject *r = PyTuple_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    } else {
        PySequenceMethods *m = Py_TYPE(o)->tp_as_sequence;
        if (likely(m && m->sq_item)) {
            if (wraparound && unlikely(i < 0) && likely(m->sq_length)) {
                Py_ssize_t l = m->sq_length(o);
                if (likely(l >= 0)) {
                    i += l;
                } else {
                    if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                        return NULL;
                    PyErr_Clear();
                }
            }
            return m->sq_item(o, i);
        }
    }
#else
    if (is_list || PySequence_Check(o)) {
        return PySequence_GetItem(o, i);
    }
#endif
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
}

/* ObjectGetItem */
#if CYTHON_USE_TYPE_SLOTS
static PyObject *__Pyx_PyObject_GetIndex(PyObject *obj, PyObject* index) {
    PyObject *runerr;
    Py_ssize_t key_value;
    PySequenceMethods *m = Py_TYPE(obj)->tp_as_sequence;
    if (unlikely(!(m && m->sq_item))) {
        PyErr_Format(PyExc_TypeError, "'%.200s' object is not subscriptable", Py_TYPE(obj)->tp_name);
        return NULL;
    }
    key_value = __Pyx_PyIndex_AsSsize_t(index);
    if (likely(key_value != -1 || !(runerr = PyErr_Occurred()))) {
        return __Pyx_GetItemInt_Fast(obj, key_value, 0, 1, 1);
    }
    if (PyErr_GivenExceptionMatches(runerr, PyExc_OverflowError)) {
        PyErr_Clear();
        PyErr_Format(PyExc_IndexError, "cannot fit '%.200s' into an index-sized integer", Py_TYPE(index)->tp_name);
    }
    return NULL;
}
static PyObject *__Pyx_PyObject_GetItem(PyObject *obj, PyObject* key) {
    PyMappingMethods *m = Py_TYPE(obj)->tp_as_mapping;
    if (likely(m && m->mp_subscript)) {
        return m->mp_subscript(obj, key);
    }
    return __Pyx_PyObject_GetIndex(obj, key);
}
#endif

/* SliceObject */
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetSlice(PyObject* obj,
        Py_ssize_t cstart, Py_ssize_t cstop,
        PyObject** _py_start, PyObject** _py_stop, PyObject** _py_slice,
        int has_cstart, int has_cstop, CYTHON_UNUSED int wraparound) {
#if CYTHON_USE_TYPE_SLOTS
    PyMappingMethods* mp;
#if PY_MAJOR_VERSION < 3
    PySequenceMethods* ms = Py_TYPE(obj)->tp_as_sequence;
    if (likely(ms && ms->sq_slice)) {
        if (!has_cstart) {
            if (_py_start && (*_py_start != Py_None)) {
                cstart = __Pyx_PyIndex_AsSsize_t(*_py_start);
                if ((cstart == (Py_ssize_t)-1) && PyErr_Occurred()) goto bad;
            } else
                cstart = 0;
        }
        if (!has_cstop) {
            if (_py_stop && (*_py_stop != Py_None)) {
                cstop = __Pyx_PyIndex_AsSsize_t(*_py_stop);
                if ((cstop == (Py_ssize_t)-1) && PyErr_Occurred()) goto bad;
            } else
                cstop = PY_SSIZE_T_MAX;
        }
        if (wraparound && unlikely((cstart < 0) | (cstop < 0)) && likely(ms->sq_length)) {
            Py_ssize_t l = ms->sq_length(obj);
            if (likely(l >= 0)) {
                if (cstop < 0) {
                    cstop += l;
                    if (cstop < 0) cstop = 0;
                }
                if (cstart < 0) {
                    cstart += l;
                    if (cstart < 0) cstart = 0;
                }
            } else {
                if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                    goto bad;
                PyErr_Clear();
            }
        }
        return ms->sq_slice(obj, cstart, cstop);
    }
#endif
    mp = Py_TYPE(obj)->tp_as_mapping;
    if (likely(mp && mp->mp_subscript))
#endif
    {
        PyObject* result;
        PyObject *py_slice, *py_start, *py_stop;
        if (_py_slice) {
            py_slice = *_py_slice;
        } else {
            PyObject* owned_start = NULL;
            PyObject* owned_stop = NULL;
            if (_py_start) {
                py_start = *_py_start;
            } else {
                if (has_cstart) {
                    owned_start = py_start = PyInt_FromSsize_t(cstart);
                    if (unlikely(!py_start)) goto bad;
                } else
                    py_start = Py_None;
            }
            if (_py_stop) {
                py_stop = *_py_stop;
            } else {
                if (has_cstop) {
                    owned_stop = py_stop = PyInt_FromSsize_t(cstop);
                    if (unlikely(!py_stop)) {
                        Py_XDECREF(owned_start);
                        goto bad;
                    }
                } else
                    py_stop = Py_None;
            }
            py_slice = PySlice_New(py_start, py_stop, Py_None);
            Py_XDECREF(owned_start);
            Py_XDECREF(owned_stop);
            if (unlikely(!py_slice)) goto bad;
        }
#if CYTHON_USE_TYPE_SLOTS
        result = mp->mp_subscript(obj, py_slice);
#else
        result = PyObject_GetItem(obj, py_slice);
#endif
        if (!_py_slice) {
            Py_DECREF(py_slice);
        }
        return result;
    }
    PyErr_Format(PyExc_TypeError,
        "'%.200s' object is unsliceable", Py_TYPE(obj)->tp_name);
bad:
    return NULL;
}

/* None */
static CYTHON_INLINE void __Pyx_RaiseClosureNameError(const char *varname) {
    PyErr_Format(PyExc_NameError, "free variable '%s' referenced before assignment in enclosing scope", varname);
}

/* RaiseArgTupleInvalid */
static void __Pyx_RaiseArgtupleInvalid(
    const char* func_name,
    int exact,
    Py_ssize_t num_min,
    Py_ssize_t num_max,
    Py_ssize_t num_found)
{
    Py_ssize_t num_expected;
    const char *more_or_less;
    if (num_found < num_min) {
        num_expected = num_min;
        more_or_less = "at least";
    } else {
        num_expected = num_max;
        more_or_less = "at most";
    }
    if (exact) {
        more_or_less = "exactly";
    }
    PyErr_Format(PyExc_TypeError,
                 "%.200s() takes %.8s %" CYTHON_FORMAT_SSIZE_T "d positional argument%.1s (%" CYTHON_FORMAT_SSIZE_T "d given)",
                 func_name, more_or_less, num_expected,
                 (num_expected == 1) ? "" : "s", num_found);
}

/* RaiseDoubleKeywords */
static void __Pyx_RaiseDoubleKeywordsError(
    const char* func_name,
    PyObject* kw_name)
{
    PyErr_Format(PyExc_TypeError,
        #if PY_MAJOR_VERSION >= 3
        "%s() got multiple values for keyword argument '%U'", func_name, kw_name);
        #else
        "%s() got multiple values for keyword argument '%s'", func_name,
        PyString_AsString(kw_name));
        #endif
}

/* ParseKeywords */
static int __Pyx_ParseOptionalKeywords(
    PyObject *kwds,
    PyObject **argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    const char* function_name)
{
    PyObject *key = 0, *value = 0;
    Py_ssize_t pos = 0;
    PyObject*** name;
    PyObject*** first_kw_arg = argnames + num_pos_args;
    while (PyDict_Next(kwds, &pos, &key, &value)) {
        name = first_kw_arg;
        while (*name && (**name != key)) name++;
        if (*name) {
            values[name-argnames] = value;
            continue;
        }
        name = first_kw_arg;
        #if PY_MAJOR_VERSION < 3
        if (likely(PyString_CheckExact(key)) || likely(PyString_Check(key))) {
            while (*name) {
                if ((CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**name) == PyString_GET_SIZE(key))
                        && _PyString_Eq(**name, key)) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    if ((**argname == key) || (
                            (CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**argname) == PyString_GET_SIZE(key))
                             && _PyString_Eq(**argname, key))) {
                        goto arg_passed_twice;
                    }
                    argname++;
                }
            }
        } else
        #endif
        if (likely(PyUnicode_Check(key))) {
            while (*name) {
                int cmp = (**name == key) ? 0 :
                #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                    (PyUnicode_GET_SIZE(**name) != PyUnicode_GET_SIZE(key)) ? 1 :
                #endif
                    PyUnicode_Compare(**name, key);
                if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                if (cmp == 0) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    int cmp = (**argname == key) ? 0 :
                    #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                        (PyUnicode_GET_SIZE(**argname) != PyUnicode_GET_SIZE(key)) ? 1 :
                    #endif
                        PyUnicode_Compare(**argname, key);
                    if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                    if (cmp == 0) goto arg_passed_twice;
                    argname++;
                }
            }
        } else
            goto invalid_keyword_type;
        if (kwds2) {
            if (unlikely(PyDict_SetItem(kwds2, key, value))) goto bad;
        } else {
            goto invalid_keyword;
        }
    }
    return 0;
arg_passed_twice:
    __Pyx_RaiseDoubleKeywordsError(function_name, key);
    goto bad;
invalid_keyword_type:
    PyErr_Format(PyExc_TypeError,
        "%.200s() keywords must be strings", function_name);
    goto bad;
invalid_keyword:
    PyErr_Format(PyExc_TypeError,
    #if PY_MAJOR_VERSION < 3
        "%.200s() got an unexpected keyword argument '%.200s'",
        function_name, PyString_AsString(key));
    #else
        "%s() got an unexpected keyword argument '%U'",
        function_name, key);
    #endif
bad:
    return -1;
}

/* PyObjectCallNoArg */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, NULL, 0);
    }
#endif
#ifdef __Pyx_CyFunction_USED
    if (likely(PyCFunction_Check(func) || __Pyx_CyFunction_Check(func)))
#else
    if (likely(PyCFunction_Check(func)))
#endif
    {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_NOARGS)) {
            return __Pyx_PyObject_CallMethO(func, NULL);
        }
    }
    return __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL);
}
#endif

/* GetTopmostException */
#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem *
__Pyx_PyErr_GetTopmostException(PyThreadState *tstate)
{
    _PyErr_StackItem *exc_info = tstate->exc_info;
    while ((exc_info->exc_type == NULL || exc_info->exc_type == Py_None) &&
           exc_info->previous_item != NULL)
    {
        exc_info = exc_info->previous_item;
    }
    return exc_info;
}
#endif

/* SaveResetException */
#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = __Pyx_PyErr_GetTopmostException(tstate);
    *type = exc_info->exc_type;
    *value = exc_info->exc_value;
    *tb = exc_info->exc_traceback;
    #else
    *type = tstate->exc_type;
    *value = tstate->exc_value;
    *tb = tstate->exc_traceback;
    #endif
    Py_XINCREF(*type);
    Py_XINCREF(*value);
    Py_XINCREF(*tb);
}
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = type;
    exc_info->exc_value = value;
    exc_info->exc_traceback = tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = type;
    tstate->exc_value = value;
    tstate->exc_traceback = tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
#endif

/* GetException */
#if CYTHON_FAST_THREAD_STATE
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb)
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb)
#endif
{
    PyObject *local_type, *local_value, *local_tb;
#if CYTHON_FAST_THREAD_STATE
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    local_type = tstate->curexc_type;
    local_value = tstate->curexc_value;
    local_tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
#else
    PyErr_Fetch(&local_type, &local_value, &local_tb);
#endif
    PyErr_NormalizeException(&local_type, &local_value, &local_tb);
#if CYTHON_FAST_THREAD_STATE
    if (unlikely(tstate->curexc_type))
#else
    if (unlikely(PyErr_Occurred()))
#endif
        goto bad;
    #if PY_MAJOR_VERSION >= 3
    if (local_tb) {
        if (unlikely(PyException_SetTraceback(local_value, local_tb) < 0))
            goto bad;
    }
    #endif
    Py_XINCREF(local_tb);
    Py_XINCREF(local_type);
    Py_XINCREF(local_value);
    *type = local_type;
    *value = local_value;
    *tb = local_tb;
#if CYTHON_FAST_THREAD_STATE
    #if CYTHON_USE_EXC_INFO_STACK
    {
        _PyErr_StackItem *exc_info = tstate->exc_info;
        tmp_type = exc_info->exc_type;
        tmp_value = exc_info->exc_value;
        tmp_tb = exc_info->exc_traceback;
        exc_info->exc_type = local_type;
        exc_info->exc_value = local_value;
        exc_info->exc_traceback = local_tb;
    }
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = local_type;
    tstate->exc_value = local_value;
    tstate->exc_traceback = local_tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
#else
    PyErr_SetExcInfo(local_type, local_value, local_tb);
#endif
    return 0;
bad:
    *type = 0;
    *value = 0;
    *tb = 0;
    Py_XDECREF(local_type);
    Py_XDECREF(local_value);
    Py_XDECREF(local_tb);
    return -1;
}

/* PyErrFetchRestore */
#if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    tmp_type = tstate->curexc_type;
    tmp_value = tstate->curexc_value;
    tmp_tb = tstate->curexc_traceback;
    tstate->curexc_type = type;
    tstate->curexc_value = value;
    tstate->curexc_traceback = tb;
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    *type = tstate->curexc_type;
    *value = tstate->curexc_value;
    *tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
}
#endif

/* None */
static CYTHON_INLINE void __Pyx_RaiseUnboundLocalError(const char *varname) {
    PyErr_Format(PyExc_UnboundLocalError, "local variable '%s' referenced before assignment", varname);
}

/* FetchCommonType */
static PyTypeObject* __Pyx_FetchCommonType(PyTypeObject* type) {
    PyObject* fake_module;
    PyTypeObject* cached_type = NULL;
    fake_module = PyImport_AddModule((char*) "_cython_" CYTHON_ABI);
    if (!fake_module) return NULL;
    Py_INCREF(fake_module);
    cached_type = (PyTypeObject*) PyObject_GetAttrString(fake_module, type->tp_name);
    if (cached_type) {
        if (!PyType_Check((PyObject*)cached_type)) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s is not a type object",
                type->tp_name);
            goto bad;
        }
        if (cached_type->tp_basicsize != type->tp_basicsize) {
            PyErr_Format(PyExc_TypeError,
                "Shared Cython type %.200s has the wrong size, try recompiling",
                type->tp_name);
            goto bad;
        }
    } else {
        if (!PyErr_ExceptionMatches(PyExc_AttributeError)) goto bad;
        PyErr_Clear();
        if (PyType_Ready(type) < 0) goto bad;
        if (PyObject_SetAttrString(fake_module, type->tp_name, (PyObject*) type) < 0)
            goto bad;
        Py_INCREF(type);
        cached_type = type;
    }
done:
    Py_DECREF(fake_module);
    return cached_type;
bad:
    Py_XDECREF(cached_type);
    cached_type = NULL;
    goto done;
}

/* CythonFunction */
#include <structmember.h>
static PyObject *
__Pyx_CyFunction_get_doc(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *closure)
{
    if (unlikely(op->func_doc == NULL)) {
        if (op->func.m_ml->ml_doc) {
#if PY_MAJOR_VERSION >= 3
            op->func_doc = PyUnicode_FromString(op->func.m_ml->ml_doc);
#else
            op->func_doc = PyString_FromString(op->func.m_ml->ml_doc);
#endif
            if (unlikely(op->func_doc == NULL))
                return NULL;
        } else {
            Py_INCREF(Py_None);
            return Py_None;
        }
    }
    Py_INCREF(op->func_doc);
    return op->func_doc;
}
static int
__Pyx_CyFunction_set_doc(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp = op->func_doc;
    if (value == NULL) {
        value = Py_None;
    }
    Py_INCREF(value);
    op->func_doc = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_name(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_name == NULL)) {
#if PY_MAJOR_VERSION >= 3
        op->func_name = PyUnicode_InternFromString(op->func.m_ml->ml_name);
#else
        op->func_name = PyString_InternFromString(op->func.m_ml->ml_name);
#endif
        if (unlikely(op->func_name == NULL))
            return NULL;
    }
    Py_INCREF(op->func_name);
    return op->func_name;
}
static int
__Pyx_CyFunction_set_name(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__name__ must be set to a string object");
        return -1;
    }
    tmp = op->func_name;
    Py_INCREF(value);
    op->func_name = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_qualname(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_qualname);
    return op->func_qualname;
}
static int
__Pyx_CyFunction_set_qualname(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
#if PY_MAJOR_VERSION >= 3
    if (unlikely(value == NULL || !PyUnicode_Check(value)))
#else
    if (unlikely(value == NULL || !PyString_Check(value)))
#endif
    {
        PyErr_SetString(PyExc_TypeError,
                        "__qualname__ must be set to a string object");
        return -1;
    }
    tmp = op->func_qualname;
    Py_INCREF(value);
    op->func_qualname = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_self(__pyx_CyFunctionObject *m, CYTHON_UNUSED void *closure)
{
    PyObject *self;
    self = m->func_closure;
    if (self == NULL)
        self = Py_None;
    Py_INCREF(self);
    return self;
}
static PyObject *
__Pyx_CyFunction_get_dict(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    if (unlikely(op->func_dict == NULL)) {
        op->func_dict = PyDict_New();
        if (unlikely(op->func_dict == NULL))
            return NULL;
    }
    Py_INCREF(op->func_dict);
    return op->func_dict;
}
static int
__Pyx_CyFunction_set_dict(__pyx_CyFunctionObject *op, PyObject *value, CYTHON_UNUSED void *context)
{
    PyObject *tmp;
    if (unlikely(value == NULL)) {
        PyErr_SetString(PyExc_TypeError,
               "function's dictionary may not be deleted");
        return -1;
    }
    if (unlikely(!PyDict_Check(value))) {
        PyErr_SetString(PyExc_TypeError,
               "setting function's dictionary to a non-dict");
        return -1;
    }
    tmp = op->func_dict;
    Py_INCREF(value);
    op->func_dict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_globals(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(op->func_globals);
    return op->func_globals;
}
static PyObject *
__Pyx_CyFunction_get_closure(CYTHON_UNUSED __pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    Py_INCREF(Py_None);
    return Py_None;
}
static PyObject *
__Pyx_CyFunction_get_code(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context)
{
    PyObject* result = (op->func_code) ? op->func_code : Py_None;
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_init_defaults(__pyx_CyFunctionObject *op) {
    int result = 0;
    PyObject *res = op->defaults_getter((PyObject *) op);
    if (unlikely(!res))
        return -1;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    op->defaults_tuple = PyTuple_GET_ITEM(res, 0);
    Py_INCREF(op->defaults_tuple);
    op->defaults_kwdict = PyTuple_GET_ITEM(res, 1);
    Py_INCREF(op->defaults_kwdict);
    #else
    op->defaults_tuple = PySequence_ITEM(res, 0);
    if (unlikely(!op->defaults_tuple)) result = -1;
    else {
        op->defaults_kwdict = PySequence_ITEM(res, 1);
        if (unlikely(!op->defaults_kwdict)) result = -1;
    }
    #endif
    Py_DECREF(res);
    return result;
}
static int
__Pyx_CyFunction_set_defaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyTuple_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__defaults__ must be set to a tuple object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_tuple;
    op->defaults_tuple = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_defaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_tuple;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_tuple;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_kwdefaults(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value) {
        value = Py_None;
    } else if (value != Py_None && !PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__kwdefaults__ must be set to a dict object");
        return -1;
    }
    Py_INCREF(value);
    tmp = op->defaults_kwdict;
    op->defaults_kwdict = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_kwdefaults(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->defaults_kwdict;
    if (unlikely(!result)) {
        if (op->defaults_getter) {
            if (__Pyx_CyFunction_init_defaults(op) < 0) return NULL;
            result = op->defaults_kwdict;
        } else {
            result = Py_None;
        }
    }
    Py_INCREF(result);
    return result;
}
static int
__Pyx_CyFunction_set_annotations(__pyx_CyFunctionObject *op, PyObject* value, CYTHON_UNUSED void *context) {
    PyObject* tmp;
    if (!value || value == Py_None) {
        value = NULL;
    } else if (!PyDict_Check(value)) {
        PyErr_SetString(PyExc_TypeError,
                        "__annotations__ must be set to a dict object");
        return -1;
    }
    Py_XINCREF(value);
    tmp = op->func_annotations;
    op->func_annotations = value;
    Py_XDECREF(tmp);
    return 0;
}
static PyObject *
__Pyx_CyFunction_get_annotations(__pyx_CyFunctionObject *op, CYTHON_UNUSED void *context) {
    PyObject* result = op->func_annotations;
    if (unlikely(!result)) {
        result = PyDict_New();
        if (unlikely(!result)) return NULL;
        op->func_annotations = result;
    }
    Py_INCREF(result);
    return result;
}
static PyGetSetDef __pyx_CyFunction_getsets[] = {
    {(char *) "func_doc", (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "__doc__",  (getter)__Pyx_CyFunction_get_doc, (setter)__Pyx_CyFunction_set_doc, 0, 0},
    {(char *) "func_name", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__name__", (getter)__Pyx_CyFunction_get_name, (setter)__Pyx_CyFunction_set_name, 0, 0},
    {(char *) "__qualname__", (getter)__Pyx_CyFunction_get_qualname, (setter)__Pyx_CyFunction_set_qualname, 0, 0},
    {(char *) "__self__", (getter)__Pyx_CyFunction_get_self, 0, 0, 0},
    {(char *) "func_dict", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "__dict__", (getter)__Pyx_CyFunction_get_dict, (setter)__Pyx_CyFunction_set_dict, 0, 0},
    {(char *) "func_globals", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "__globals__", (getter)__Pyx_CyFunction_get_globals, 0, 0, 0},
    {(char *) "func_closure", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "__closure__", (getter)__Pyx_CyFunction_get_closure, 0, 0, 0},
    {(char *) "func_code", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "__code__", (getter)__Pyx_CyFunction_get_code, 0, 0, 0},
    {(char *) "func_defaults", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__defaults__", (getter)__Pyx_CyFunction_get_defaults, (setter)__Pyx_CyFunction_set_defaults, 0, 0},
    {(char *) "__kwdefaults__", (getter)__Pyx_CyFunction_get_kwdefaults, (setter)__Pyx_CyFunction_set_kwdefaults, 0, 0},
    {(char *) "__annotations__", (getter)__Pyx_CyFunction_get_annotations, (setter)__Pyx_CyFunction_set_annotations, 0, 0},
    {0, 0, 0, 0, 0}
};
static PyMemberDef __pyx_CyFunction_members[] = {
    {(char *) "__module__", T_OBJECT, offsetof(PyCFunctionObject, m_module), PY_WRITE_RESTRICTED, 0},
    {0, 0, 0,  0, 0}
};
static PyObject *
__Pyx_CyFunction_reduce(__pyx_CyFunctionObject *m, CYTHON_UNUSED PyObject *args)
{
#if PY_MAJOR_VERSION >= 3
    return PyUnicode_FromString(m->func.m_ml->ml_name);
#else
    return PyString_FromString(m->func.m_ml->ml_name);
#endif
}
static PyMethodDef __pyx_CyFunction_methods[] = {
    {"__reduce__", (PyCFunction)__Pyx_CyFunction_reduce, METH_VARARGS, 0},
    {0, 0, 0, 0}
};
#if PY_VERSION_HEX < 0x030500A0
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func_weakreflist)
#else
#define __Pyx_CyFunction_weakreflist(cyfunc) ((cyfunc)->func.m_weakreflist)
#endif
static PyObject *__Pyx_CyFunction_New(PyTypeObject *type, PyMethodDef *ml, int flags, PyObject* qualname,
                                      PyObject *closure, PyObject *module, PyObject* globals, PyObject* code) {
    __pyx_CyFunctionObject *op = PyObject_GC_New(__pyx_CyFunctionObject, type);
    if (op == NULL)
        return NULL;
    op->flags = flags;
    __Pyx_CyFunction_weakreflist(op) = NULL;
    op->func.m_ml = ml;
    op->func.m_self = (PyObject *) op;
    Py_XINCREF(closure);
    op->func_closure = closure;
    Py_XINCREF(module);
    op->func.m_module = module;
    op->func_dict = NULL;
    op->func_name = NULL;
    Py_INCREF(qualname);
    op->func_qualname = qualname;
    op->func_doc = NULL;
    op->func_classobj = NULL;
    op->func_globals = globals;
    Py_INCREF(op->func_globals);
    Py_XINCREF(code);
    op->func_code = code;
    op->defaults_pyobjects = 0;
    op->defaults = NULL;
    op->defaults_tuple = NULL;
    op->defaults_kwdict = NULL;
    op->defaults_getter = NULL;
    op->func_annotations = NULL;
    PyObject_GC_Track(op);
    return (PyObject *) op;
}
static int
__Pyx_CyFunction_clear(__pyx_CyFunctionObject *m)
{
    Py_CLEAR(m->func_closure);
    Py_CLEAR(m->func.m_module);
    Py_CLEAR(m->func_dict);
    Py_CLEAR(m->func_name);
    Py_CLEAR(m->func_qualname);
    Py_CLEAR(m->func_doc);
    Py_CLEAR(m->func_globals);
    Py_CLEAR(m->func_code);
    Py_CLEAR(m->func_classobj);
    Py_CLEAR(m->defaults_tuple);
    Py_CLEAR(m->defaults_kwdict);
    Py_CLEAR(m->func_annotations);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_XDECREF(pydefaults[i]);
        PyObject_Free(m->defaults);
        m->defaults = NULL;
    }
    return 0;
}
static void __Pyx__CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    if (__Pyx_CyFunction_weakreflist(m) != NULL)
        PyObject_ClearWeakRefs((PyObject *) m);
    __Pyx_CyFunction_clear(m);
    PyObject_GC_Del(m);
}
static void __Pyx_CyFunction_dealloc(__pyx_CyFunctionObject *m)
{
    PyObject_GC_UnTrack(m);
    __Pyx__CyFunction_dealloc(m);
}
static int __Pyx_CyFunction_traverse(__pyx_CyFunctionObject *m, visitproc visit, void *arg)
{
    Py_VISIT(m->func_closure);
    Py_VISIT(m->func.m_module);
    Py_VISIT(m->func_dict);
    Py_VISIT(m->func_name);
    Py_VISIT(m->func_qualname);
    Py_VISIT(m->func_doc);
    Py_VISIT(m->func_globals);
    Py_VISIT(m->func_code);
    Py_VISIT(m->func_classobj);
    Py_VISIT(m->defaults_tuple);
    Py_VISIT(m->defaults_kwdict);
    if (m->defaults) {
        PyObject **pydefaults = __Pyx_CyFunction_Defaults(PyObject *, m);
        int i;
        for (i = 0; i < m->defaults_pyobjects; i++)
            Py_VISIT(pydefaults[i]);
    }
    return 0;
}
static PyObject *__Pyx_CyFunction_descr_get(PyObject *func, PyObject *obj, PyObject *type)
{
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    if (m->flags & __Pyx_CYFUNCTION_STATICMETHOD) {
        Py_INCREF(func);
        return func;
    }
    if (m->flags & __Pyx_CYFUNCTION_CLASSMETHOD) {
        if (type == NULL)
            type = (PyObject *)(Py_TYPE(obj));
        return __Pyx_PyMethod_New(func, type, (PyObject *)(Py_TYPE(type)));
    }
    if (obj == Py_None)
        obj = NULL;
    return __Pyx_PyMethod_New(func, obj, type);
}
static PyObject*
__Pyx_CyFunction_repr(__pyx_CyFunctionObject *op)
{
#if PY_MAJOR_VERSION >= 3
    return PyUnicode_FromFormat("<cyfunction %U at %p>",
                                op->func_qualname, (void *)op);
#else
    return PyString_FromFormat("<cyfunction %s at %p>",
                               PyString_AsString(op->func_qualname), (void *)op);
#endif
}
static PyObject * __Pyx_CyFunction_CallMethod(PyObject *func, PyObject *self, PyObject *arg, PyObject *kw) {
    PyCFunctionObject* f = (PyCFunctionObject*)func;
    PyCFunction meth = f->m_ml->ml_meth;
    Py_ssize_t size;
    switch (f->m_ml->ml_flags & (METH_VARARGS | METH_KEYWORDS | METH_NOARGS | METH_O)) {
    case METH_VARARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0))
            return (*meth)(self, arg);
        break;
    case METH_VARARGS | METH_KEYWORDS:
        return (*(PyCFunctionWithKeywords)(void*)meth)(self, arg, kw);
    case METH_NOARGS:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 0))
                return (*meth)(self, NULL);
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes no arguments (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    case METH_O:
        if (likely(kw == NULL || PyDict_Size(kw) == 0)) {
            size = PyTuple_GET_SIZE(arg);
            if (likely(size == 1)) {
                PyObject *result, *arg0;
                #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
                arg0 = PyTuple_GET_ITEM(arg, 0);
                #else
                arg0 = PySequence_ITEM(arg, 0); if (unlikely(!arg0)) return NULL;
                #endif
                result = (*meth)(self, arg0);
                #if !(CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS)
                Py_DECREF(arg0);
                #endif
                return result;
            }
            PyErr_Format(PyExc_TypeError,
                "%.200s() takes exactly one argument (%" CYTHON_FORMAT_SSIZE_T "d given)",
                f->m_ml->ml_name, size);
            return NULL;
        }
        break;
    default:
        PyErr_SetString(PyExc_SystemError, "Bad call flags in "
                        "__Pyx_CyFunction_Call. METH_OLDARGS is no "
                        "longer supported!");
        return NULL;
    }
    PyErr_Format(PyExc_TypeError, "%.200s() takes no keyword arguments",
                 f->m_ml->ml_name);
    return NULL;
}
static CYTHON_INLINE PyObject *__Pyx_CyFunction_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    return __Pyx_CyFunction_CallMethod(func, ((PyCFunctionObject*)func)->m_self, arg, kw);
}
static PyObject *__Pyx_CyFunction_CallAsMethod(PyObject *func, PyObject *args, PyObject *kw) {
    PyObject *result;
    __pyx_CyFunctionObject *cyfunc = (__pyx_CyFunctionObject *) func;
    if ((cyfunc->flags & __Pyx_CYFUNCTION_CCLASS) && !(cyfunc->flags & __Pyx_CYFUNCTION_STATICMETHOD)) {
        Py_ssize_t argc;
        PyObject *new_args;
        PyObject *self;
        argc = PyTuple_GET_SIZE(args);
        new_args = PyTuple_GetSlice(args, 1, argc);
        if (unlikely(!new_args))
            return NULL;
        self = PyTuple_GetItem(args, 0);
        if (unlikely(!self)) {
            Py_DECREF(new_args);
            return NULL;
        }
        result = __Pyx_CyFunction_CallMethod(func, self, new_args, kw);
        Py_DECREF(new_args);
    } else {
        result = __Pyx_CyFunction_Call(func, args, kw);
    }
    return result;
}
static PyTypeObject __pyx_CyFunctionType_type = {
    PyVarObject_HEAD_INIT(0, 0)
    "cython_function_or_method",
    sizeof(__pyx_CyFunctionObject),
    0,
    (destructor) __Pyx_CyFunction_dealloc,
    0,
    0,
    0,
#if PY_MAJOR_VERSION < 3
    0,
#else
    0,
#endif
    (reprfunc) __Pyx_CyFunction_repr,
    0,
    0,
    0,
    0,
    __Pyx_CyFunction_CallAsMethod,
    0,
    0,
    0,
    0,
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HAVE_GC,
    0,
    (traverseproc) __Pyx_CyFunction_traverse,
    (inquiry) __Pyx_CyFunction_clear,
    0,
#if PY_VERSION_HEX < 0x030500A0
    offsetof(__pyx_CyFunctionObject, func_weakreflist),
#else
    offsetof(PyCFunctionObject, m_weakreflist),
#endif
    0,
    0,
    __pyx_CyFunction_methods,
    __pyx_CyFunction_members,
    __pyx_CyFunction_getsets,
    0,
    0,
    __Pyx_CyFunction_descr_get,
    0,
    offsetof(__pyx_CyFunctionObject, func_dict),
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
#if PY_VERSION_HEX >= 0x030400a1
    0,
#endif
#if PY_VERSION_HEX >= 0x030800b1
    0,
#endif
};
static int __pyx_CyFunction_init(void) {
    __pyx_CyFunctionType = __Pyx_FetchCommonType(&__pyx_CyFunctionType_type);
    if (unlikely(__pyx_CyFunctionType == NULL)) {
        return -1;
    }
    return 0;
}
static CYTHON_INLINE void *__Pyx_CyFunction_InitDefaults(PyObject *func, size_t size, int pyobjects) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults = PyObject_Malloc(size);
    if (unlikely(!m->defaults))
        return PyErr_NoMemory();
    memset(m->defaults, 0, size);
    m->defaults_pyobjects = pyobjects;
    return m->defaults;
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsTuple(PyObject *func, PyObject *tuple) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_tuple = tuple;
    Py_INCREF(tuple);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetDefaultsKwDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->defaults_kwdict = dict;
    Py_INCREF(dict);
}
static CYTHON_INLINE void __Pyx_CyFunction_SetAnnotationsDict(PyObject *func, PyObject *dict) {
    __pyx_CyFunctionObject *m = (__pyx_CyFunctionObject *) func;
    m->func_annotations = dict;
    Py_INCREF(dict);
}

/* BytesEquals */
static CYTHON_INLINE int __Pyx_PyBytes_Equals(PyObject* s1, PyObject* s2, int equals) {
#if CYTHON_COMPILING_IN_PYPY
    return PyObject_RichCompareBool(s1, s2, equals);
#else
    if (s1 == s2) {
        return (equals == Py_EQ);
    } else if (PyBytes_CheckExact(s1) & PyBytes_CheckExact(s2)) {
        const char *ps1, *ps2;
        Py_ssize_t length = PyBytes_GET_SIZE(s1);
        if (length != PyBytes_GET_SIZE(s2))
            return (equals == Py_NE);
        ps1 = PyBytes_AS_STRING(s1);
        ps2 = PyBytes_AS_STRING(s2);
        if (ps1[0] != ps2[0]) {
            return (equals == Py_NE);
        } else if (length == 1) {
            return (equals == Py_EQ);
        } else {
            int result;
#if CYTHON_USE_UNICODE_INTERNALS
            Py_hash_t hash1, hash2;
            hash1 = ((PyBytesObject*)s1)->ob_shash;
            hash2 = ((PyBytesObject*)s2)->ob_shash;
            if (hash1 != hash2 && hash1 != -1 && hash2 != -1) {
                return (equals == Py_NE);
            }
#endif
            result = memcmp(ps1, ps2, (size_t)length);
            return (equals == Py_EQ) ? (result == 0) : (result != 0);
        }
    } else if ((s1 == Py_None) & PyBytes_CheckExact(s2)) {
        return (equals == Py_NE);
    } else if ((s2 == Py_None) & PyBytes_CheckExact(s1)) {
        return (equals == Py_NE);
    } else {
        int result;
        PyObject* py_result = PyObject_RichCompare(s1, s2, equals);
        if (!py_result)
            return -1;
        result = __Pyx_PyObject_IsTrue(py_result);
        Py_DECREF(py_result);
        return result;
    }
#endif
}

/* UnicodeEquals */
static CYTHON_INLINE int __Pyx_PyUnicode_Equals(PyObject* s1, PyObject* s2, int equals) {
#if CYTHON_COMPILING_IN_PYPY
    return PyObject_RichCompareBool(s1, s2, equals);
#else
#if PY_MAJOR_VERSION < 3
    PyObject* owned_ref = NULL;
#endif
    int s1_is_unicode, s2_is_unicode;
    if (s1 == s2) {
        goto return_eq;
    }
    s1_is_unicode = PyUnicode_CheckExact(s1);
    s2_is_unicode = PyUnicode_CheckExact(s2);
#if PY_MAJOR_VERSION < 3
    if ((s1_is_unicode & (!s2_is_unicode)) && PyString_CheckExact(s2)) {
        owned_ref = PyUnicode_FromObject(s2);
        if (unlikely(!owned_ref))
            return -1;
        s2 = owned_ref;
        s2_is_unicode = 1;
    } else if ((s2_is_unicode & (!s1_is_unicode)) && PyString_CheckExact(s1)) {
        owned_ref = PyUnicode_FromObject(s1);
        if (unlikely(!owned_ref))
            return -1;
        s1 = owned_ref;
        s1_is_unicode = 1;
    } else if (((!s2_is_unicode) & (!s1_is_unicode))) {
        return __Pyx_PyBytes_Equals(s1, s2, equals);
    }
#endif
    if (s1_is_unicode & s2_is_unicode) {
        Py_ssize_t length;
        int kind;
        void *data1, *data2;
        if (unlikely(__Pyx_PyUnicode_READY(s1) < 0) || unlikely(__Pyx_PyUnicode_READY(s2) < 0))
            return -1;
        length = __Pyx_PyUnicode_GET_LENGTH(s1);
        if (length != __Pyx_PyUnicode_GET_LENGTH(s2)) {
            goto return_ne;
        }
#if CYTHON_USE_UNICODE_INTERNALS
        {
            Py_hash_t hash1, hash2;
        #if CYTHON_PEP393_ENABLED
            hash1 = ((PyASCIIObject*)s1)->hash;
            hash2 = ((PyASCIIObject*)s2)->hash;
        #else
            hash1 = ((PyUnicodeObject*)s1)->hash;
            hash2 = ((PyUnicodeObject*)s2)->hash;
        #endif
            if (hash1 != hash2 && hash1 != -1 && hash2 != -1) {
                goto return_ne;
            }
        }
#endif
        kind = __Pyx_PyUnicode_KIND(s1);
        if (kind != __Pyx_PyUnicode_KIND(s2)) {
            goto return_ne;
        }
        data1 = __Pyx_PyUnicode_DATA(s1);
        data2 = __Pyx_PyUnicode_DATA(s2);
        if (__Pyx_PyUnicode_READ(kind, data1, 0) != __Pyx_PyUnicode_READ(kind, data2, 0)) {
            goto return_ne;
        } else if (length == 1) {
            goto return_eq;
        } else {
            int result = memcmp(data1, data2, (size_t)(length * kind));
            #if PY_MAJOR_VERSION < 3
            Py_XDECREF(owned_ref);
            #endif
            return (equals == Py_EQ) ? (result == 0) : (result != 0);
        }
    } else if ((s1 == Py_None) & s2_is_unicode) {
        goto return_ne;
    } else if ((s2 == Py_None) & s1_is_unicode) {
        goto return_ne;
    } else {
        int result;
        PyObject* py_result = PyObject_RichCompare(s1, s2, equals);
        #if PY_MAJOR_VERSION < 3
        Py_XDECREF(owned_ref);
        #endif
        if (!py_result)
            return -1;
        result = __Pyx_PyObject_IsTrue(py_result);
        Py_DECREF(py_result);
        return result;
    }
return_eq:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(owned_ref);
    #endif
    return (equals == Py_EQ);
return_ne:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(owned_ref);
    #endif
    return (equals == Py_NE);
#endif
}

/* PyObject_GenericGetAttrNoDict */
#if CYTHON_USE_TYPE_SLOTS && CYTHON_USE_PYTYPE_LOOKUP && PY_VERSION_HEX < 0x03070000
static PyObject *__Pyx_RaiseGenericGetAttributeError(PyTypeObject *tp, PyObject *attr_name) {
    PyErr_Format(PyExc_AttributeError,
#if PY_MAJOR_VERSION >= 3
                 "'%.50s' object has no attribute '%U'",
                 tp->tp_name, attr_name);
#else
                 "'%.50s' object has no attribute '%.400s'",
                 tp->tp_name, PyString_AS_STRING(attr_name));
#endif
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_GenericGetAttrNoDict(PyObject* obj, PyObject* attr_name) {
    PyObject *descr;
    PyTypeObject *tp = Py_TYPE(obj);
    if (unlikely(!PyString_Check(attr_name))) {
        return PyObject_GenericGetAttr(obj, attr_name);
    }
    assert(!tp->tp_dictoffset);
    descr = _PyType_Lookup(tp, attr_name);
    if (unlikely(!descr)) {
        return __Pyx_RaiseGenericGetAttributeError(tp, attr_name);
    }
    Py_INCREF(descr);
    #if PY_MAJOR_VERSION < 3
    if (likely(PyType_HasFeature(Py_TYPE(descr), Py_TPFLAGS_HAVE_CLASS)))
    #endif
    {
        descrgetfunc f = Py_TYPE(descr)->tp_descr_get;
        if (unlikely(f)) {
            PyObject *res = f(descr, obj, (PyObject *)tp);
            Py_DECREF(descr);
            return res;
        }
    }
    return descr;
}
#endif

/* Import */
static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level) {
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    #if PY_MAJOR_VERSION < 3
    PyObject *py_import;
    py_import = __Pyx_PyObject_GetAttrStr(__pyx_b, __pyx_n_s_import);
    if (!py_import)
        goto bad;
    #endif
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    {
        #if PY_MAJOR_VERSION >= 3
        if (level == -1) {
            if (strchr(__Pyx_MODULE_NAME, '.')) {
                module = PyImport_ImportModuleLevelObject(
                    name, global_dict, empty_dict, list, 1);
                if (!module) {
                    if (!PyErr_ExceptionMatches(PyExc_ImportError))
                        goto bad;
                    PyErr_Clear();
                }
            }
            level = 0;
        }
        #endif
        if (!module) {
            #if PY_MAJOR_VERSION < 3
            PyObject *py_level = PyInt_FromLong(level);
            if (!py_level)
                goto bad;
            module = PyObject_CallFunctionObjArgs(py_import,
                name, global_dict, empty_dict, list, py_level, (PyObject *)NULL);
            Py_DECREF(py_level);
            #else
            module = PyImport_ImportModuleLevelObject(
                name, global_dict, empty_dict, list, level);
            #endif
        }
    }
bad:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(py_import);
    #endif
    Py_XDECREF(empty_list);
    Py_XDECREF(empty_dict);
    return module;
}

/* ImportFrom */
static PyObject* __Pyx_ImportFrom(PyObject* module, PyObject* name) {
    PyObject* value = __Pyx_PyObject_GetAttrStr(module, name);
    if (unlikely(!value) && PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Format(PyExc_ImportError,
        #if PY_MAJOR_VERSION < 3
            "cannot import name %.230s", PyString_AS_STRING(name));
        #else
            "cannot import name %S", name);
        #endif
    }
    return value;
}

/* PyErrExceptionMatches */
#if CYTHON_FAST_THREAD_STATE
static int __Pyx_PyErr_ExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        if (__Pyx_PyErr_GivenExceptionMatches(exc_type, PyTuple_GET_ITEM(tuple, i))) return 1;
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_ExceptionMatchesInState(PyThreadState* tstate, PyObject* err) {
    PyObject *exc_type = tstate->curexc_type;
    if (exc_type == err) return 1;
    if (unlikely(!exc_type)) return 0;
    if (unlikely(PyTuple_Check(err)))
        return __Pyx_PyErr_ExceptionMatchesTuple(exc_type, err);
    return __Pyx_PyErr_GivenExceptionMatches(exc_type, err);
}
#endif

/* CLineInTraceback */
#ifndef CYTHON_CLINE_IN_TRACEBACK
static int __Pyx_CLineForTraceback(PyThreadState *tstate, int c_line) {
    PyObject *use_cline;
    PyObject *ptype, *pvalue, *ptraceback;
#if CYTHON_COMPILING_IN_CPYTHON
    PyObject **cython_runtime_dict;
#endif
    if (unlikely(!__pyx_cython_runtime)) {
        return c_line;
    }
    __Pyx_ErrFetchInState(tstate, &ptype, &pvalue, &ptraceback);
#if CYTHON_COMPILING_IN_CPYTHON
    cython_runtime_dict = _PyObject_GetDictPtr(__pyx_cython_runtime);
    if (likely(cython_runtime_dict)) {
        __PYX_PY_DICT_LOOKUP_IF_MODIFIED(
            use_cline, *cython_runtime_dict,
            __Pyx_PyDict_GetItemStr(*cython_runtime_dict, __pyx_n_s_cline_in_traceback))
    } else
#endif
    {
      PyObject *use_cline_obj = __Pyx_PyObject_GetAttrStr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback);
      if (use_cline_obj) {
        use_cline = PyObject_Not(use_cline_obj) ? Py_False : Py_True;
        Py_DECREF(use_cline_obj);
      } else {
        PyErr_Clear();
        use_cline = NULL;
      }
    }
    if (!use_cline) {
        c_line = 0;
        PyObject_SetAttr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback, Py_False);
    }
    else if (use_cline == Py_False || (use_cline != Py_True && PyObject_Not(use_cline) != 0)) {
        c_line = 0;
    }
    __Pyx_ErrRestoreInState(tstate, ptype, pvalue, ptraceback);
    return c_line;
}
#endif

/* CodeObjectCache */
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line) {
    int start = 0, mid = 0, end = count - 1;
    if (end >= 0 && code_line > entries[end].code_line) {
        return count;
    }
    while (start < end) {
        mid = start + (end - start) / 2;
        if (code_line < entries[mid].code_line) {
            end = mid;
        } else if (code_line > entries[mid].code_line) {
             start = mid + 1;
        } else {
            return mid;
        }
    }
    if (code_line <= entries[mid].code_line) {
        return mid;
    } else {
        return mid + 1;
    }
}
static PyCodeObject *__pyx_find_code_object(int code_line) {
    PyCodeObject* code_object;
    int pos;
    if (unlikely(!code_line) || unlikely(!__pyx_code_cache.entries)) {
        return NULL;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if (unlikely(pos >= __pyx_code_cache.count) || unlikely(__pyx_code_cache.entries[pos].code_line != code_line)) {
        return NULL;
    }
    code_object = __pyx_code_cache.entries[pos].code_object;
    Py_INCREF(code_object);
    return code_object;
}
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object) {
    int pos, i;
    __Pyx_CodeObjectCacheEntry* entries = __pyx_code_cache.entries;
    if (unlikely(!code_line)) {
        return;
    }
    if (unlikely(!entries)) {
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Malloc(64*sizeof(__Pyx_CodeObjectCacheEntry));
        if (likely(entries)) {
            __pyx_code_cache.entries = entries;
            __pyx_code_cache.max_count = 64;
            __pyx_code_cache.count = 1;
            entries[0].code_line = code_line;
            entries[0].code_object = code_object;
            Py_INCREF(code_object);
        }
        return;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if ((pos < __pyx_code_cache.count) && unlikely(__pyx_code_cache.entries[pos].code_line == code_line)) {
        PyCodeObject* tmp = entries[pos].code_object;
        entries[pos].code_object = code_object;
        Py_DECREF(tmp);
        return;
    }
    if (__pyx_code_cache.count == __pyx_code_cache.max_count) {
        int new_max = __pyx_code_cache.max_count + 64;
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Realloc(
            __pyx_code_cache.entries, (size_t)new_max*sizeof(__Pyx_CodeObjectCacheEntry));
        if (unlikely(!entries)) {
            return;
        }
        __pyx_code_cache.entries = entries;
        __pyx_code_cache.max_count = new_max;
    }
    for (i=__pyx_code_cache.count; i>pos; i--) {
        entries[i] = entries[i-1];
    }
    entries[pos].code_line = code_line;
    entries[pos].code_object = code_object;
    __pyx_code_cache.count++;
    Py_INCREF(code_object);
}

/* AddTraceback */
#include "compile.h"
#include "frameobject.h"
#include "traceback.h"
static PyCodeObject* __Pyx_CreateCodeObjectForTraceback(
            const char *funcname, int c_line,
            int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    #if PY_MAJOR_VERSION < 3
    py_srcfile = PyString_FromString(filename);
    #else
    py_srcfile = PyUnicode_FromString(filename);
    #endif
    if (!py_srcfile) goto bad;
    if (c_line) {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #else
        py_funcname = PyUnicode_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #endif
    }
    else {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromString(funcname);
        #else
        py_funcname = PyUnicode_FromString(funcname);
        #endif
    }
    if (!py_funcname) goto bad;
    py_code = __Pyx_PyCode_New(
        0,
        0,
        0,
        0,
        0,
        __pyx_empty_bytes, /*PyObject *code,*/
        __pyx_empty_tuple, /*PyObject *consts,*/
        __pyx_empty_tuple, /*PyObject *names,*/
        __pyx_empty_tuple, /*PyObject *varnames,*/
        __pyx_empty_tuple, /*PyObject *freevars,*/
        __pyx_empty_tuple, /*PyObject *cellvars,*/
        py_srcfile,   /*PyObject *filename,*/
        py_funcname,  /*PyObject *name,*/
        py_line,
        __pyx_empty_bytes  /*PyObject *lnotab*/
    );
    Py_DECREF(py_srcfile);
    Py_DECREF(py_funcname);
    return py_code;
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    return NULL;
}
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    if (c_line) {
        c_line = __Pyx_CLineForTraceback(tstate, c_line);
    }
    py_code = __pyx_find_code_object(c_line ? -c_line : py_line);
    if (!py_code) {
        py_code = __Pyx_CreateCodeObjectForTraceback(
            funcname, c_line, py_line, filename);
        if (!py_code) goto bad;
        __pyx_insert_code_object(c_line ? -c_line : py_line, py_code);
    }
    py_frame = PyFrame_New(
        tstate,            /*PyThreadState *tstate,*/
        py_code,           /*PyCodeObject *code,*/
        __pyx_d,    /*PyObject *globals,*/
        0                  /*PyObject *locals*/
    );
    if (!py_frame) goto bad;
    __Pyx_PyFrame_SetLineNumber(py_frame, py_line);
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}

/* None */
#ifdef __FreeBSD__
#include <floatingpoint.h>
#endif
#if PY_MAJOR_VERSION < 3
int main(int argc, char** argv) {
#elif defined(WIN32) || defined(MS_WINDOWS)
int wmain(int argc, wchar_t **argv) {
#else
static int __Pyx_main(int argc, wchar_t **argv) {
#endif
    /* 754 requires that FP exceptions run in "no stop" mode by default,
     * and until C vendors implement C99's ways to control FP exceptions,
     * Python requires non-stop mode.  Alas, some platforms enable FP
     * exceptions by default.  Here we disable them.
     */
#ifdef __FreeBSD__
    fp_except_t m;
    m = fpgetmask();
    fpsetmask(m & ~FP_X_OFL);
#endif
    if (argc && argv)
        Py_SetProgramName(argv[0]);
    Py_Initialize();
    if (argc && argv)
        PySys_SetArgv(argc, argv);
    {
      PyObject* m = NULL;
      __pyx_module_is_main_cryptz = 1;
      #if PY_MAJOR_VERSION < 3
          initcryptz();
      #elif CYTHON_PEP489_MULTI_PHASE_INIT
          m = PyInit_cryptz();
          if (!PyModule_Check(m)) {
              PyModuleDef *mdef = (PyModuleDef *) m;
              PyObject *modname = PyUnicode_FromString("__main__");
              m = NULL;
              if (modname) {
                  m = PyModule_NewObject(modname);
                  Py_DECREF(modname);
                  if (m) PyModule_ExecDef(m, mdef);
              }
          }
      #else
          m = PyInit_cryptz();
      #endif
      if (PyErr_Occurred()) {
          PyErr_Print();
          #if PY_MAJOR_VERSION < 3
          if (Py_FlushLine()) PyErr_Clear();
          #endif
          return 1;
      }
      Py_XDECREF(m);
    }
    Py_Finalize();
    return 0;
}
#if PY_MAJOR_VERSION >= 3 && !defined(WIN32) && !defined(MS_WINDOWS)
#include <locale.h>
static wchar_t*
__Pyx_char2wchar(char* arg)
{
    wchar_t *res;
#ifdef HAVE_BROKEN_MBSTOWCS
    /* Some platforms have a broken implementation of
     * mbstowcs which does not count the characters that
     * would result from conversion.  Use an upper bound.
     */
    size_t argsize = strlen(arg);
#else
    size_t argsize = mbstowcs(NULL, arg, 0);
#endif
    size_t count;
    unsigned char *in;
    wchar_t *out;
#ifdef HAVE_MBRTOWC
    mbstate_t mbs;
#endif
    if (argsize != (size_t)-1) {
        res = (wchar_t *)malloc((argsize+1)*sizeof(wchar_t));
        if (!res)
            goto oom;
        count = mbstowcs(res, arg, argsize+1);
        if (count != (size_t)-1) {
            wchar_t *tmp;
            /* Only use the result if it contains no
               surrogate characters. */
            for (tmp = res; *tmp != 0 &&
                     (*tmp < 0xd800 || *tmp > 0xdfff); tmp++)
                ;
            if (*tmp == 0)
                return res;
        }
        free(res);
    }
#ifdef HAVE_MBRTOWC
    /* Overallocate; as multi-byte characters are in the argument, the
       actual output could use less memory. */
    argsize = strlen(arg) + 1;
    res = (wchar_t *)malloc(argsize*sizeof(wchar_t));
    if (!res) goto oom;
    in = (unsigned char*)arg;
    out = res;
    memset(&mbs, 0, sizeof mbs);
    while (argsize) {
        size_t converted = mbrtowc(out, (char*)in, argsize, &mbs);
        if (converted == 0)
            break;
        if (converted == (size_t)-2) {
            /* Incomplete character. This should never happen,
               since we provide everything that we have -
               unless there is a bug in the C library, or I
               misunderstood how mbrtowc works. */
            fprintf(stderr, "unexpected mbrtowc result -2\\n");
            free(res);
            return NULL;
        }
        if (converted == (size_t)-1) {
            /* Conversion error. Escape as UTF-8b, and start over
               in the initial shift state. */
            *out++ = 0xdc00 + *in++;
            argsize--;
            memset(&mbs, 0, sizeof mbs);
            continue;
        }
        if (*out >= 0xd800 && *out <= 0xdfff) {
            /* Surrogate character.  Escape the original
               byte sequence with surrogateescape. */
            argsize -= converted;
            while (converted--)
                *out++ = 0xdc00 + *in++;
            continue;
        }
        in += converted;
        argsize -= converted;
        out++;
    }
#else
    /* Cannot use C locale for escaping; manually escape as if charset
       is ASCII (i.e. escape all bytes > 128. This will still roundtrip
       correctly in the locale's charset, which must be an ASCII superset. */
    res = (wchar_t *)malloc((strlen(arg)+1)*sizeof(wchar_t));
    if (!res) goto oom;
    in = (unsigned char*)arg;
    out = res;
    while(*in)
        if(*in < 128)
            *out++ = *in++;
        else
            *out++ = 0xdc00 + *in++;
    *out = 0;
#endif
    return res;
oom:
    fprintf(stderr, "out of memory\\n");
    return NULL;
}
int
main(int argc, char **argv)
{
    if (!argc) {
        return __Pyx_main(0, NULL);
    }
    else {
        int i, res;
        wchar_t **argv_copy = (wchar_t **)malloc(sizeof(wchar_t*)*argc);
        wchar_t **argv_copy2 = (wchar_t **)malloc(sizeof(wchar_t*)*argc);
        char *oldloc = strdup(setlocale(LC_ALL, NULL));
        if (!argv_copy || !argv_copy2 || !oldloc) {
            fprintf(stderr, "out of memory\\n");
            free(argv_copy);
            free(argv_copy2);
            free(oldloc);
            return 1;
        }
        res = 0;
        setlocale(LC_ALL, "");
        for (i = 0; i < argc; i++) {
            argv_copy2[i] = argv_copy[i] = __Pyx_char2wchar(argv[i]);
            if (!argv_copy[i]) res = 1;
        }
        setlocale(LC_ALL, oldloc);
        free(oldloc);
        if (res == 0)
            res = __Pyx_main(argc, argv_copy);
        for (i = 0; i < argc; i++) {
            free(argv_copy2[i]);
        }
        free(argv_copy);
        free(argv_copy2);
        return res;
    }
}
#endif

/* CIntToPy */
    static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value) {
    const long neg_one = (long) ((long) 0 - (long) 1), const_zero = (long) 0;
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(long) < sizeof(long)) {
            return PyInt_FromLong((long) value);
        } else if (sizeof(long) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(long) <= sizeof(long)) {
            return PyInt_FromLong((long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
#endif
        }
    }
    {
        int one = 1; int little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&value;
        return _PyLong_FromByteArray(bytes, sizeof(long),
                                     little, !is_unsigned);
    }
}

/* CIntFromPyVerify */
    #define __PYX_VERIFY_RETURN_INT(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 0)
#define __PYX_VERIFY_RETURN_INT_EXC(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 1)
#define __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, exc)\
    {\
        func_type value = func_value;\
        if (sizeof(target_type) < sizeof(func_type)) {\
            if (unlikely(value != (func_type) (target_type) value)) {\
                func_type zero = 0;\
                if (exc && unlikely(value == (func_type)-1 && PyErr_Occurred()))\
                    return (target_type) -1;\
                if (is_unsigned && unlikely(value < zero))\
                    goto raise_neg_overflow;\
                else\
                    goto raise_overflow;\
            }\
        }\
        return (target_type) value;\
    }

/* CIntFromPy */
    static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *x) {
    const long neg_one = (long) ((long) 0 - (long) 1), const_zero = (long) 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(long) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(long, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (long) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case  1: __PYX_VERIFY_RETURN_INT(long, digit, digits[0])
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 2 * PyLong_SHIFT) {
                            return (long) (((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 3 * PyLong_SHIFT) {
                            return (long) (((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 4 * PyLong_SHIFT) {
                            return (long) (((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (long) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(long) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case -1: __PYX_VERIFY_RETURN_INT(long, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(long,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(long) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) ((((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) ((((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) ((((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(long) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            long val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (long) -1;
        }
    } else {
        long val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (long) -1;
        val = __Pyx_PyInt_As_long(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to long");
    return (long) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to long");
    return (long) -1;
}

/* CIntFromPy */
    static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *x) {
    const int neg_one = (int) ((int) 0 - (int) 1), const_zero = (int) 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(int) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(int, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (int) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case  1: __PYX_VERIFY_RETURN_INT(int, digit, digits[0])
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 2 * PyLong_SHIFT) {
                            return (int) (((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 3 * PyLong_SHIFT) {
                            return (int) (((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 4 * PyLong_SHIFT) {
                            return (int) (((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (int) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(int) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case -1: __PYX_VERIFY_RETURN_INT(int, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(int,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(int) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) ((((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) ((((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) ((((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(int) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            int val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (int) -1;
        }
    } else {
        int val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (int) -1;
        val = __Pyx_PyInt_As_int(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to int");
    return (int) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to int");
    return (int) -1;
}

/* FastTypeChecks */
    #if CYTHON_COMPILING_IN_CPYTHON
static int __Pyx_InBases(PyTypeObject *a, PyTypeObject *b) {
    while (a) {
        a = a->tp_base;
        if (a == b)
            return 1;
    }
    return b == &PyBaseObject_Type;
}
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b) {
    PyObject *mro;
    if (a == b) return 1;
    mro = a->tp_mro;
    if (likely(mro)) {
        Py_ssize_t i, n;
        n = PyTuple_GET_SIZE(mro);
        for (i = 0; i < n; i++) {
            if (PyTuple_GET_ITEM(mro, i) == (PyObject *)b)
                return 1;
        }
        return 0;
    }
    return __Pyx_InBases(a, b);
}
#if PY_MAJOR_VERSION == 2
static int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject* exc_type2) {
    PyObject *exception, *value, *tb;
    int res;
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&exception, &value, &tb);
    res = exc_type1 ? PyObject_IsSubclass(err, exc_type1) : 0;
    if (unlikely(res == -1)) {
        PyErr_WriteUnraisable(err);
        res = 0;
    }
    if (!res) {
        res = PyObject_IsSubclass(err, exc_type2);
        if (unlikely(res == -1)) {
            PyErr_WriteUnraisable(err);
            res = 0;
        }
    }
    __Pyx_ErrRestore(exception, value, tb);
    return res;
}
#else
static CYTHON_INLINE int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject *exc_type2) {
    int res = exc_type1 ? __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type1) : 0;
    if (!res) {
        res = __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type2);
    }
    return res;
}
#endif
static int __Pyx_PyErr_GivenExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    assert(PyExceptionClass_Check(exc_type));
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        PyObject *t = PyTuple_GET_ITEM(tuple, i);
        #if PY_MAJOR_VERSION < 3
        if (likely(exc_type == t)) return 1;
        #endif
        if (likely(PyExceptionClass_Check(t))) {
            if (__Pyx_inner_PyErr_GivenExceptionMatches2(exc_type, NULL, t)) return 1;
        } else {
        }
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject* exc_type) {
    if (likely(err == exc_type)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        if (likely(PyExceptionClass_Check(exc_type))) {
            return __Pyx_inner_PyErr_GivenExceptionMatches2(err, NULL, exc_type);
        } else if (likely(PyTuple_Check(exc_type))) {
            return __Pyx_PyErr_GivenExceptionMatchesTuple(err, exc_type);
        } else {
        }
    }
    return PyErr_GivenExceptionMatches(err, exc_type);
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *exc_type1, PyObject *exc_type2) {
    assert(PyExceptionClass_Check(exc_type1));
    assert(PyExceptionClass_Check(exc_type2));
    if (likely(err == exc_type1 || err == exc_type2)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        return __Pyx_inner_PyErr_GivenExceptionMatches2(err, exc_type1, exc_type2);
    }
    return (PyErr_GivenExceptionMatches(err, exc_type1) || PyErr_GivenExceptionMatches(err, exc_type2));
}
#endif

/* CheckBinaryVersion */
    static int __Pyx_check_binary_version(void) {
    char ctversion[4], rtversion[4];
    PyOS_snprintf(ctversion, 4, "%d.%d", PY_MAJOR_VERSION, PY_MINOR_VERSION);
    PyOS_snprintf(rtversion, 4, "%s", Py_GetVersion());
    if (ctversion[0] != rtversion[0] || ctversion[2] != rtversion[2]) {
        char message[200];
        PyOS_snprintf(message, sizeof(message),
                      "compiletime version %s of module '%.100s' "
                      "does not match runtime version %s",
                      ctversion, __Pyx_MODULE_NAME, rtversion);
        return PyErr_WarnEx(NULL, message, 1);
    }
    return 0;
}

/* InitStrings */
    static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        #if PY_MAJOR_VERSION < 3
        if (t->is_unicode) {
            *t->p = PyUnicode_DecodeUTF8(t->s, t->n - 1, NULL);
        } else if (t->intern) {
            *t->p = PyString_InternFromString(t->s);
        } else {
            *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        }
        #else
        if (t->is_unicode | t->is_str) {
            if (t->intern) {
                *t->p = PyUnicode_InternFromString(t->s);
            } else if (t->encoding) {
                *t->p = PyUnicode_Decode(t->s, t->n - 1, t->encoding, NULL);
            } else {
                *t->p = PyUnicode_FromStringAndSize(t->s, t->n - 1);
            }
        } else {
            *t->p = PyBytes_FromStringAndSize(t->s, t->n - 1);
        }
        #endif
        if (!*t->p)
            return -1;
        if (PyObject_Hash(*t->p) == -1)
            return -1;
        ++t;
    }
    return 0;
}

static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char* c_str) {
    return __Pyx_PyUnicode_FromStringAndSize(c_str, (Py_ssize_t)strlen(c_str));
}
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject* o) {
    Py_ssize_t ignore;
    return __Pyx_PyObject_AsStringAndSize(o, &ignore);
}
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
#if !CYTHON_PEP393_ENABLED
static const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    char* defenc_c;
    PyObject* defenc = _PyUnicode_AsDefaultEncodedString(o, NULL);
    if (!defenc) return NULL;
    defenc_c = PyBytes_AS_STRING(defenc);
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    {
        char* end = defenc_c + PyBytes_GET_SIZE(defenc);
        char* c;
        for (c = defenc_c; c < end; c++) {
            if ((unsigned char) (*c) >= 128) {
                PyUnicode_AsASCIIString(o);
                return NULL;
            }
        }
    }
#endif
    *length = PyBytes_GET_SIZE(defenc);
    return defenc_c;
}
#else
static CYTHON_INLINE const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    if (unlikely(__Pyx_PyUnicode_READY(o) == -1)) return NULL;
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    if (likely(PyUnicode_IS_ASCII(o))) {
        *length = PyUnicode_GET_LENGTH(o);
        return PyUnicode_AsUTF8(o);
    } else {
        PyUnicode_AsASCIIString(o);
        return NULL;
    }
#else
    return PyUnicode_AsUTF8AndSize(o, length);
#endif
}
#endif
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
    if (
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
            __Pyx_sys_getdefaultencoding_not_ascii &&
#endif
            PyUnicode_Check(o)) {
        return __Pyx_PyUnicode_AsStringAndSize(o, length);
    } else
#endif
#if (!CYTHON_COMPILING_IN_PYPY) || (defined(PyByteArray_AS_STRING) && defined(PyByteArray_GET_SIZE))
    if (PyByteArray_Check(o)) {
        *length = PyByteArray_GET_SIZE(o);
        return PyByteArray_AS_STRING(o);
    } else
#endif
    {
        char* result;
        int r = PyBytes_AsStringAndSize(o, &result, length);
        if (unlikely(r < 0)) {
            return NULL;
        } else {
            return result;
        }
    }
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject* x) {
   int is_true = x == Py_True;
   if (is_true | (x == Py_False) | (x == Py_None)) return is_true;
   else return PyObject_IsTrue(x);
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject* x) {
    int retval;
    if (unlikely(!x)) return -1;
    retval = __Pyx_PyObject_IsTrue(x);
    Py_DECREF(x);
    return retval;
}
static PyObject* __Pyx_PyNumber_IntOrLongWrongResultType(PyObject* result, const char* type_name) {
#if PY_MAJOR_VERSION >= 3
    if (PyLong_Check(result)) {
        if (PyErr_WarnFormat(PyExc_DeprecationWarning, 1,
                "__int__ returned non-int (type %.200s).  "
                "The ability to return an instance of a strict subclass of int "
                "is deprecated, and may be removed in a future version of Python.",
                Py_TYPE(result)->tp_name)) {
            Py_DECREF(result);
            return NULL;
        }
        return result;
    }
#endif
    PyErr_Format(PyExc_TypeError,
                 "__%.4s__ returned non-%.4s (type %.200s)",
                 type_name, type_name, Py_TYPE(result)->tp_name);
    Py_DECREF(result);
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x) {
#if CYTHON_USE_TYPE_SLOTS
  PyNumberMethods *m;
#endif
  const char *name = NULL;
  PyObject *res = NULL;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_Check(x) || PyLong_Check(x)))
#else
  if (likely(PyLong_Check(x)))
#endif
    return __Pyx_NewRef(x);
#if CYTHON_USE_TYPE_SLOTS
  m = Py_TYPE(x)->tp_as_number;
  #if PY_MAJOR_VERSION < 3
  if (m && m->nb_int) {
    name = "int";
    res = m->nb_int(x);
  }
  else if (m && m->nb_long) {
    name = "long";
    res = m->nb_long(x);
  }
  #else
  if (likely(m && m->nb_int)) {
    name = "int";
    res = m->nb_int(x);
  }
  #endif
#else
  if (!PyBytes_CheckExact(x) && !PyUnicode_CheckExact(x)) {
    res = PyNumber_Int(x);
  }
#endif
  if (likely(res)) {
#if PY_MAJOR_VERSION < 3
    if (unlikely(!PyInt_Check(res) && !PyLong_Check(res))) {
#else
    if (unlikely(!PyLong_CheckExact(res))) {
#endif
        return __Pyx_PyNumber_IntOrLongWrongResultType(res, name);
    }
  }
  else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_TypeError,
                    "an integer is required");
  }
  return res;
}
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject* b) {
  Py_ssize_t ival;
  PyObject *x;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_CheckExact(b))) {
    if (sizeof(Py_ssize_t) >= sizeof(long))
        return PyInt_AS_LONG(b);
    else
        return PyInt_AsSsize_t(b);
  }
#endif
  if (likely(PyLong_CheckExact(b))) {
    #if CYTHON_USE_PYLONG_INTERNALS
    const digit* digits = ((PyLongObject*)b)->ob_digit;
    const Py_ssize_t size = Py_SIZE(b);
    if (likely(__Pyx_sst_abs(size) <= 1)) {
        ival = likely(size) ? digits[0] : 0;
        if (size == -1) ival = -ival;
        return ival;
    } else {
      switch (size) {
         case 2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
      }
    }
    #endif
    return PyLong_AsSsize_t(b);
  }
  x = PyNumber_Index(b);
  if (!x) return -1;
  ival = PyInt_AsSsize_t(x);
  Py_DECREF(x);
  return ival;
}
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b) {
  return b ? __Pyx_NewRef(Py_True) : __Pyx_NewRef(Py_False);
}
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t ival) {
    return PyInt_FromSize_t(ival);
}


#endif /* Py_PYTHON_H */
