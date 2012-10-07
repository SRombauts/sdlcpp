#include "backtrace.h"

#ifdef unix

#include <iostream>
#include <execinfo.h>
#include <cxxabi.h>
#include <stdlib.h>

void print_backtrace(void)
{
    const size_t    maxDepth = 100;
    size_t          stackDepth;
    void*           stackAddresses[maxDepth];
    char**          pStackStrings;

    stackDepth      = backtrace(stackAddresses, maxDepth);
    pStackStrings   = backtrace_symbols(stackAddresses, stackDepth);

    std::cout << "backtrace:" << std::endl;

    for (size_t stackFrame = 2; stackFrame < stackDepth; stackFrame++)
    {
        size_t buffSize     = 256;
        char* pFunctionName = (char*)malloc(buffSize);
        char* pBegin = NULL;
        char* pPlus  = NULL;
        char* pEnd   = NULL;
        // find the parentheses and address offset surrounding the mangled name
        char* pChar = pStackStrings[stackFrame];
        while ('\0' != *pChar)
        {
            if (*pChar == '(')
            {
                pBegin = pChar;
            }
            else if (*pChar == '+')
            {
                pPlus = pChar;
            }
            else if (*pChar == ')')
            {
                pEnd = pChar;
            }
            pChar++;
        }
        if (   (NULL != pBegin)
            && (NULL != pPlus)
            && (NULL != pEnd)
            && (pPlus > pBegin + 1) )
        {
            *pBegin++   = '\0';
            *pPlus++    = '\0';
            *pEnd       = '\0';

            int status;
            pFunctionName[0] = '\0';
            char* pDemangledFunctionName = abi::__cxa_demangle(pBegin, pFunctionName, &buffSize, &status);
            if (pDemangledFunctionName)
            {
                // return value may be a realloc() of the input
                pFunctionName = pDemangledFunctionName;
                std::cout << "    " << pFunctionName << " +" << pPlus << std::endl;
            }
            else
            {
                // demangling failed, just pretend it's a C function with no args
                std::cout << "    " << pBegin << "() +" << pPlus << std::endl;
            }
        }
        else
        {
            // didn't find the mangled name, just print the whole line
            std::cout << "    " << pStackStrings[stackFrame] << std::endl;
        }
        free(pFunctionName);
    }
    free(pStackStrings); // malloc()ed by backtrace_symbols
}

#else

void print_backtrace(void)
{
}

#endif
