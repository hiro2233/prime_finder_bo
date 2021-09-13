
WORKDIR = `pwd`

CC ?= $(CC)
CXX ?= $(CXX)
AR ?= $(AR)
LD = $(CXX)
WINDRES ?= 

INC ?= 
CFLAGS ?= -Wall
RESINC ?= 
LIBDIR ?= 
LIB ?=
LDFLAGS ?= 

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB) 
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = build/.obj/Debug
DEP_DEBUG = 
OUT_DEBUG = build/Debug/prime_number_santacruz

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2 -ffunction-sections -fdata-sections -fno-exceptions -fsigned-char -fpermissive -Wpointer-arith -Wwrite-strings -Wno-unused-parameter -fno-threadsafe-statics -Wno-unknown-pragmas -Wno-overflow -Wno-sign-compare -Wno-missing-field-initializers -Wno-trigraphs
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB) 
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = build/.obj/Release
DEP_RELEASE = 
OUT_RELEASE = build/Release/prime_number_santacruz

OBJ_DEBUG = $(OBJDIR_DEBUG)/prime_number_santacruz.o

OBJ_RELEASE = $(OBJDIR_RELEASE)/prime_number_santacruz.o

all: debug release

clean: clean_debug clean_release

before_debug: 
	test -d build/Debug || mkdir -p build/Debug
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)/prime_number_santacruz.o: prime_number_santacruz.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c prime_number_santacruz.cpp -o $(OBJDIR_DEBUG)/prime_number_santacruz.o

clean_debug: 
	rm -f $(OBJ_DEBUG) $(OUT_DEBUG)
	rm -rf build/Debug
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d build/Release || mkdir -p build/Release
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/prime_number_santacruz.o: prime_number_santacruz.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c prime_number_santacruz.cpp -o $(OBJDIR_RELEASE)/prime_number_santacruz.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf build/Release
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

