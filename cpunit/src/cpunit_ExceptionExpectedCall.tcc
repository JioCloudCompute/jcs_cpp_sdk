/*
   Copyright (c) 2011 Daniel Bakkelund.
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions
   are met:
    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the names of its
       contributors may be used to endorse or promote products derived from
       this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
   THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "cpunit_trace.hpp"
#include "cpunit_Assert.hpp"

template<class ExceptionType>
cpunit::ExceptionExpectedCall<ExceptionType>::ExceptionExpectedCall(const RegInfo &ri, TestMethod _test) 
  : Callable(ri)
  , test(_test)
{}

template<class ExceptionType>
cpunit::ExceptionExpectedCall<ExceptionType>::~ExceptionExpectedCall() 
{}

template<class ExceptionType>
void
cpunit::ExceptionExpectedCall<ExceptionType>::run() {
  CPUNIT_DTRACE("ExceptionExpectedCall::run called");
  bool exceptionThrown = true;
  try {
    (*test)();
    exceptionThrown = false;
  } catch (AssertionException &e) {
    throw e;
  } catch (ExceptionType &e) {
    CPUNIT_DTRACE("ExceptionExpectedCall::run succeeded");
  }
  if (!exceptionThrown) {
    fail("No exception thrown from tested code.");
  }
}