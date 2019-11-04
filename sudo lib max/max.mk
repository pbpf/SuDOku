##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=max
ConfigurationName      :=Debug
WorkspacePath          := "D:\Project-eps\shudu\sudo lib max"
ProjectPath            := "D:\Project-eps\shudu\sudo lib max"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=connor
Date                   :=09/17/14
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
LinkerName             :=D:/Tools/MinGW-4.8.1/bin/g++.exe 
SharedObjectLinkerName :=D:/Tools/MinGW-4.8.1/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="max.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=D:/Tools/MinGW-4.8.1/bin/windres.exe 
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := D:/Tools/MinGW-4.8.1/bin/ar.exe rcu
CXX      := D:/Tools/MinGW-4.8.1/bin/g++.exe 
CC       := D:/Tools/MinGW-4.8.1/bin/gcc.exe 
CXXFLAGS :=  -g $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := D:/Tools/MinGW-4.8.1/bin/as.exe 


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=D:\Tools\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/Sudo.cpp$(ObjectSuffix) $(IntermediateDirectory)/bit_matrix.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Sudo.cpp$(ObjectSuffix): Sudo.cpp $(IntermediateDirectory)/Sudo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Project-eps/shudu/sudo lib max/Sudo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Sudo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Sudo.cpp$(DependSuffix): Sudo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Sudo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Sudo.cpp$(DependSuffix) -MM "Sudo.cpp"

$(IntermediateDirectory)/Sudo.cpp$(PreprocessSuffix): Sudo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Sudo.cpp$(PreprocessSuffix) "Sudo.cpp"

$(IntermediateDirectory)/bit_matrix.cpp$(ObjectSuffix): bit_matrix.cpp $(IntermediateDirectory)/bit_matrix.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Project-eps/shudu/sudo lib max/bit_matrix.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/bit_matrix.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/bit_matrix.cpp$(DependSuffix): bit_matrix.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/bit_matrix.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/bit_matrix.cpp$(DependSuffix) -MM "bit_matrix.cpp"

$(IntermediateDirectory)/bit_matrix.cpp$(PreprocessSuffix): bit_matrix.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/bit_matrix.cpp$(PreprocessSuffix) "bit_matrix.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) ".build-debug/max"


