
### Options: ###

# C++ compiler 
CXX = g++

# flags for C++ 
# TODO SRombauts :
# -Weffc++ pose problème
# -Werror
# -Wzero-as-null-pointer-constant ?
CXXFLAGS ?= -Wall -Wextra -pedantic -Wformat-security -Winit-self -Wswitch-default -Wswitch-enum -Wfloat-equal -Wundef -Wshadow -Wcast-qual -Wconversion -Wlogical-op -Wmissing-declarations -Winline -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn

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

SDLCPP_CXXFLAGS = $(BUILD_FLAGS) $(CXXFLAGS)
SDLCPP_OBJECTS =  \
	$(BUILD)/SdlCpp_main.o \
	$(BUILD)/SdlCpp_Animation.o \
	$(BUILD)/SdlCpp_Entity.o \
	$(BUILD)/SdlCpp_Image.o \
	$(BUILD)/SdlCpp_Position.o \
	$(BUILD)/SdlCpp_Rect.o \
	$(BUILD)/SdlCpp_Screen.o \
	$(BUILD)/SdlCpp_Sprite.o \
	$(BUILD)/SdlCpp_Surface.o \
	$(BUILD)/SdlCpp_Zone.o \
	
	
### Targets: ###

all: $(BUILD) $(BUILD)/sdlcpp

clean: 
	rm -f $(BUILD)/*.o
	rm -f $(BUILD)/*.d
	rm -f $(BUILD)/sdlcpp

$(BUILD): $(BUILD)/
	mkdir -p $(BUILD)

$(BUILD)/sdlcpp: $(SDLCPP_OBJECTS)
	$(CXX) -o $@ $(SDLCPP_OBJECTS) $(LINK_FLAGS) -lSDL


$(BUILD)/SdlCpp_main.o: src/main.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_Animation.o: src/Animation.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_Entity.o: src/Entity.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_Image.o: src/Image.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_Position.o: src/Position.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_Rect.o: src/Rect.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_Screen.o: src/Screen.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_Sprite.o: src/Sprite.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_Surface.o: src/Surface.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_Zone.o: src/Zone.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

.PHONY: all clean


# Dependencies tracking:
-include $(BUILD)/*.d


