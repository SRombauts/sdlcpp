
### Options: ###

# C++ compiler 
CXX = g++

# flags for C++
CXXFLAGS ?= -Wall -Wextra -pedantic -Wformat-security -Winit-self -Wswitch-default -Wswitch-enum -Wfloat-equal -Wundef -Wshadow -Wcast-qual -Wconversion -Wlogical-op -Winline -Wsuggest-attribute=pure -Wsuggest-attribute=const -Wsuggest-attribute=noreturn

# [Debug,Release]
BUILD ?= Debug

### Conditionally set variables: ###

ifeq ($(BUILD),Debug)
BUILD_FLAGS = -g3 -rdynamic -fstack-protector-all -fno-inline -O0 -DDEBUG -D_DEBUG
endif
ifeq ($(BUILD),Release)
BUILD_FLAGS = -O2
endif
ifeq ($(BUILD),Debug)
LINK_FLAGS = -g3 -rdynamic
endif
ifeq ($(BUILD),Release)
LINK_FLAGS =
endif

### Variables: ###

CPPDEPS = -MT $@ -MF`echo $@ | sed -e 's,\.o$$,.d,'` -MD -MP

SDLCPP_CXXFLAGS = $(BUILD_FLAGS) $(CXXFLAGS)
SDLCPP_OBJECTS =  \
	$(BUILD)/SdlCpp_main.o \
	$(BUILD)/SdlCpp_backtrace.o \
	$(BUILD)/SdlCpp_signal_handler.o \
	$(BUILD)/SdlCpp_engine_Animation.o \
	$(BUILD)/SdlCpp_engine_Coord.o \
	$(BUILD)/SdlCpp_engine_Drag.o \
	$(BUILD)/SdlCpp_engine_Image.o \
	$(BUILD)/SdlCpp_engine_Offset.o \
	$(BUILD)/SdlCpp_engine_Position.o \
	$(BUILD)/SdlCpp_engine_Rect.o \
	$(BUILD)/SdlCpp_engine_Screen.o \
	$(BUILD)/SdlCpp_engine_Size.o \
	$(BUILD)/SdlCpp_engine_Sprite.o \
	$(BUILD)/SdlCpp_engine_Surface.o \
	$(BUILD)/SdlCpp_engine_UI.o \
	$(BUILD)/SdlCpp_engine_UnitEnemy.o \
	$(BUILD)/SdlCpp_engine_UnitPlayer.o \
	$(BUILD)/SdlCpp_engine_UnitTower.o \
	$(BUILD)/SdlCpp_engine_Zone.o \
	$(BUILD)/SdlCpp_engine_ZoneManager.o \
	
	
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

$(BUILD)/SdlCpp_backtrace.o: src/backtrace.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_signal_handler.o: src/signal_handler.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<


$(BUILD)/SdlCpp_engine_Animation.o: src/engine/Animation.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_Coord.o: src/engine/Coord.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_Drag.o: src/engine/Drag.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_Image.o: src/engine/Image.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_Offset.o: src/engine/Offset.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_Position.o: src/engine/Position.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_Rect.o: src/engine/Rect.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_Screen.o: src/engine/Screen.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_Size.o: src/engine/Size.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_Sprite.o: src/engine/Sprite.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_Surface.o: src/engine/Surface.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_UI.o: src/engine/UI.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_UnitEnemy.o: src/engine/UnitEnemy.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_UnitPlayer.o: src/engine/UnitPlayer.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_UnitTower.o: src/engine/UnitTower.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_Zone.o: src/engine/Zone.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

$(BUILD)/SdlCpp_engine_ZoneManager.o: src/engine/ZoneManager.cpp
	$(CXX) -c -o $@ $(SDLCPP_CXXFLAGS) $(CPPDEPS) $<

.PHONY: all clean


# Dependencies tracking:
-include $(BUILD)/*.d


