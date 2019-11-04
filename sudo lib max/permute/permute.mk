##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=permute
ConfigurationName      :=Debug
WorkspacePath          := "D:\Basic Project Frame Work\eps\shudu\sudo lib max"
ProjectPath            := "D:\Basic Project Frame Work\eps\shudu\sudo lib max\permute"
IntermediateDirectory  :=Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=connor
Date                   :=05/01/14
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName).dll
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="permute.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  /DEF:$(ProjectName).def /DEBUG
IncludePath            :=  $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  /Zi $(Preprocessors)
CFLAGS   :=  /Zi $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=D:\Tools\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/def$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "D:\Basic Project Frame Work\eps\shudu\sudo lib max/.build-debug"
	@echo rebuilt > "D:\Basic Project Frame Work\eps\shudu\sudo lib max/.build-debug/permute"

Debug:
	@$(MakeDirCommand) "Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/def$(ObjectSuffix): def.cpp $(IntermediateDirectory)/def$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Basic Project Frame Work/eps/shudu/sudo lib max/permute/def.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/def$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/def$(DependSuffix): def.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/def$(ObjectSuffix) -MF$(IntermediateDirectory)/def$(DependSuffix) -MM "def.cpp"

$(IntermediateDirectory)/def$(PreprocessSuffix): def.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/def$(PreprocessSuffix) "def.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/def$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/def$(DependSuffix)
	$(RM) $(IntermediateDirectory)/def$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile)
	$(RM) "../.build-debug/permute"


