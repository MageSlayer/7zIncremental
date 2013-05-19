PROG = 7zDec
LIB =
RM = rm -f

CFLAGS = -c -Wall
# debug/release flags
CFLAGS_DEBUG=-O0 -g -ggdb -g3
CFLAGS_RELEASE=-O2 -fomit-frame-pointer

ifeq ($(CPU_TARGET),x86_64)
  # 64 bit target

  ifeq ($(OS_TARGET),win64)
    CXX = x86_64-w64-mingw32-g++
  endif

  ifeq ($(OS_TARGET),linux)
    CXX = x86_64-pc-linux-gnu-g++
  endif

endif

ifeq ($(CPU_TARGET),i386)
  # 32 bit target

  ifeq ($(OS_TARGET),win32)
    CXX = i686-w64-mingw32-g++
  endif

  ifeq ($(OS_TARGET),linux)
    CXX = i686-pc-linux-gnu-g++
  endif

endif

ifeq ($(CXX),)
  $(error Invalid/unsupported CPU_TARGET/OS_TARGET combination)
endif

# set debug by default
ifeq ($(DEBUG),)
  override DEBUG=1
endif

# keep obj for debug and release in separate directories
OBJ_DIR_ROOT=obj
ifeq ($(DEBUG),0)
  OBJ_DIR_PREFIX=release
  CFLAGS:=$(CFLAGS) $(CFLAGS_RELEASE)
  else
  OBJ_DIR_PREFIX=debug
  CFLAGS:=$(CFLAGS) $(CFLAGS_DEBUG)
endif

OBJ_DIR=$(OBJ_DIR_ROOT)/$(OBJ_DIR_PREFIX)/$(CPU_TARGET)-$(OS_TARGET)

all :
	$(MAKE) -f makefile.gcc CXX=$(CXX) OBJ_DIR=$(OBJ_DIR) CFLAGS="$(CFLAGS)"

clean :
	$(MAKE) -f makefile.gcc clean OBJ_DIR=$(OBJ_DIR)
