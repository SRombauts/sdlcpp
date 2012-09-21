
### Options: ###

# C++ compiler 
CXX = g++

# flags for C++ 
CXXFLAGS ?= -Wall -Wextra

# [Debug,Release]
BUILD ?= Debug

### Conditionally set variables: ###

ifeq ($(BUILD),Debug)
BUILD_FLAGS = -g -rdynamic -fno-inline -O0 -DDEBUG -D_DEBUG
endif
ifeq ($(BUILD),Release)
BUILD_FLAGS = -O2
endif
ifeq ($(BUILD),Debug)
LINK_FLAGS = -g -rdynamic
endif
ifeq ($(BUILD),Release)
LINK_FLAGS =
endif

### Variables: ###

CPPDEPS = -MT $@ -MF`echo $@ | sed -e 's,\.o$$,.d,'` -MD -MP

SDL_TUTORIAL_CXXFLAGS = $(BUILD_FLAGS) $(CXXFLAGS)
SDL_TUTORIAL_OBJECTS =  \
	$(BUILD)/SdlTutorial_main.o \
	$(BUILD)/SdlTutorial_Screen.o \
	$(BUILD)/SdlTutorial_Image.o \
	
	
### Targets: ###

all: $(BUILD) $(BUILD)/sdl_tutorial

clean: 
	rm -f $(BUILD)/*.o
	rm -f $(BUILD)/*.d
	rm -f $(BUILD)/sdl_tutorial

$(BUILD): $(BUILD)/
	mkdir -p $(BUILD)

$(BUILD)/sdl_tutorial: $(SDL_TUTORIAL_OBJECTS)
	$(CXX) -o $@ $(SDL_TUTORIAL_OBJECTS) $(LINK_FLAGS) -lSDL


$(BUILD)/SdlTutorial_main.o: src/main.cpp
	$(CXX) -c -o $@ $(SDL_TUTORIAL_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlTutorial_Image.o: src/Image.cpp
	$(CXX) -c -o $@ $(SDL_TUTORIAL_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlTutorial_Screen.o: src/Screen.cpp
	$(CXX) -c -o $@ $(SDL_TUTORIAL_CXXFLAGS) $(CPPDEPS) $<

.PHONY: all clean


# Dependencies tracking:
-include $(BUILD)/*.d


