.SUFFIXES: .cpp .hpp

# Programs
SHELL 	= bash
CC     	= g++
CP = cp
LD	= ld
RM 	= rm
AR = ar rcs
ECHO = /bin/echo
CAT	= cat
PRINTF	= printf
SED	= sed
DOXYGEN = doxygen
INSTALL = apt-get install
OPENSSL = libssl-dev
CURL = libcurl4-openssl-dev
######################################
# Project Name (generate Libraries with this name)
TARGETSTATIC = libcompute.a
TARGETSHARED = libcompute.so
# Project Paths
PROJECT_ROOT=.
SRC = $(PROJECT_ROOT)/src
EXTERNAL_ROOT=$(PROJECT_ROOT)/external
SRCDIR = $(SRC) $(PROJECT_ROOT)/src/compute_api/source $(PROJECT_ROOT)/src/compute_api/source/model $(PROJECT_ROOT)/src/tinyxml2
INCDIR = $(SRC) $(PROJECT_ROOT)/src/compute_api/include/model
OBJDIR = $(PROJECT_ROOT)/obj
BINDIR = $(PROJECT_ROOT)/bin
DOCDIR = $(PROJECT_ROOT)/doc

# Library Paths
LIBPATH = /usr/lib/

#Libraries
LIBS = -lcrypto -lcurl

# Compiler and Linker flags
CPPFLAGS =-g

######################################

NO_COLOR=\e[0m
OK_COLOR=\e[1;32m
ERR_COLOR=\e[1;31m
WARN_COLOR=\e[1;33m
MESG_COLOR=\e[1;34m
FILE_COLOR=\e[1;37m

OK_STRING="[OK]"
ERR_STRING="[ERRORS]"
WARN_STRING="[WARNINGS]"
OK_FMT="${OK_COLOR}%30s\n${NO_COLOR}"
ERR_FMT="${ERR_COLOR}%30s\n${NO_COLOR}"
WARN_FMT="${WARN_COLOR}%30s\n${NO_COLOR}"
######################################

SRCS := $(foreach dir,$(SRCDIR),$(wildcard $(dir)/*.cpp))
INCS := $(foreach dir,$(INCDIR),$(wildcard $(dir)/*.hpp))
TEMP := $(SRCS:.cpp=.o)
OBJSTATIC := $(TEMP:./src/%=./obj/static/%)
OBJSHARED := $(TEMP:./src/%=./obj/shared/%)
.PHONY: all setup doc clean distclean install

all: initial $(BINDIR)/$(TARGETSTATIC) $(BINDIR)/$(TARGETSHARED)

setup:
	@$(ECHO) "Setting up compilation..."
	@sudo $(INSTALL) $(OPENSSL)
	@sudo $(INSTALL) $(CURL)
initial:
	@mkdir -p obj
	@mkdir -p bin
	@mkdir -p $(SRCDIR:$(SRC)/%=$(OBJDIR)/static/%) $(SRCDIR:$(SRC)/%=$(OBJDIR)/shared/%)
install:
	@$(PRINTF) "$(MESG_COLOR)Installing Required Libraries$(NO_COLOR) $(FILE_COLOR) %16s$(NO_COLOR)" 
	@sudo $(CP) $(BINDIR)/{$(TARGETSTATIC),$(TARGETSHARED)} $(LIBPATH) 

$(BINDIR)/$(TARGETSTATIC): $(OBJSTATIC)
	@$(PRINTF) "$(MESG_COLOR)Building Static Library:$(NO_COLOR) $(FILE_COLOR) %16s$(NO_COLOR)" "$(notdir $@)"
	@$(AR) $@ $^ 2> temp.log || touch temp.err
	@if test -e temp.err; \
	then $(PRINTF) $(ERR_FMT) $(ERR_STRING) && $(CAT) temp.log; \
	elif test -s temp.log; \
	then $(PRINTF) $(WARN_FMT) $(WARN_STRING) && $(CAT) temp.log; \
	else $(PRINTF) $(OK_FMT) $(OK_STRING); \
	fi;
	@$(RM) -f temp.log temp.err
	@$(PRINTF) "$(OK_COLOR)------------------------------------------------------------------------------\n"

$(BINDIR)/$(TARGETSHARED): $(OBJSHARED)
	@$(PRINTF) "$(MESG_COLOR)Building Shared Library:$(NO_COLOR) $(FILE_COLOR) %16s$(NO_COLOR)" "$(notdir $@)"
	@$(CC) -shared -o $@ $^ $(LIBS)  2> temp.log || touch temp.err
	@if test -e temp.err; \
	then $(PRINTF) $(ERR_FMT) $(ERR_STRING) && $(CAT) temp.log; \
	elif test -s temp.log; \
	then $(PRINTF) $(WARN_FMT) $(WARN_STRING) && $(CAT) temp.log; \
	else $(PRINTF) $(OK_FMT) $(OK_STRING); \
	fi;
	@$(RM) -f temp.log temp.err

-include -include $(OBJS:.o=.d)

$(OBJSTATIC): obj/static/%.o : src/%.cpp 
	@$(PRINTF) "$(MESG_COLOR)Compiling: $(NO_COLOR) $(FILE_COLOR) %25s$(NO_COLOR)" "$(notdir $<)"
	@$(CC) $(CPPFLAGS) -c $< -o $@ -MD 2> temp.log || touch temp.err
	@if test -e temp.err; \
	then $(PRINTF) $(ERR_FMT) $(ERR_STRING) && $(CAT) temp.log; \
	elif test -s temp.log; \
	then $(PRINTF) $(WARN_FMT) $(WARN_STRING) && $(CAT) temp.log; \
	else printf "${OK_COLOR}%30s\n${NO_COLOR}" "[OK]"; \
	fi;
	@$(RM) -f temp.log temp.err

$(OBJSHARED): obj/shared/%.o : src/%.cpp 
	@$(PRINTF) "$(MESG_COLOR)Compiling: $(NO_COLOR) $(FILE_COLOR) %25s$(NO_COLOR)" "$(notdir $<)"
	@$(CC) $(CPPFLAGS) -c -fPIC $< -o $@ -lcurl -lcrypto -MD 2> temp.log || touch temp.err
	@if test -e temp.err; \
	then $(PRINTF) $(ERR_FMT) $(ERR_STRING) && $(CAT) temp.log; \
	elif test -s temp.log; \
	then $(PRINTF) $(WARN_FMT) $(WARN_STRING) && $(CAT) temp.log; \
	else printf "${OK_COLOR}%30s\n${NO_COLOR}" "[OK]"; \
	fi;
	@$(RM) -f temp.log temp.err

doc:
	@$(PRINTF) "$(MESG_COLOR)Generating Doxygen Documentation ...  "
	@$(RM) -rf doc/html
	@$(DOXYGEN) Doxyfile  > /dev/null 2>&1
	@$(PRINTF) "$(OK_COLOR)Done\n"

clean:
	@$(ECHO) -n "Cleaning up..."
	@$(RM) -rf $(OBJDIR)
	@$(ECHO) "Done"

distclean: clean
	@$(RM) -rf $(BINDIR) $(DOCDIR)
