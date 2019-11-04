##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=sudomax
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/connor/Projects/Sudo show/sudo"
ProjectPath            := "/home/connor/Projects/Sudo show/sudo"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=connor
Date                   :=10/13/2012
CodeLitePath           :="/home/connor/.codelite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
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
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
MakeDirCommand         :=mkdir -p
CmpOptions             := -g $(Preprocessors)
LinkOptions            :=  
IncludePath            :=  "$(IncludeSwitch)." "$(IncludeSwitch)." 
RcIncludePath          :=
Libs                   :=
LibPath                := "$(LibraryPathSwitch)." 


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/Sudo show_Sudo$(ObjectSuffix) $(IntermediateDirectory)/Sudo show_bit_matrix$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Sudo show_Sudo$(ObjectSuffix): ../Sudo.cpp $(IntermediateDirectory)/Sudo show_Sudo$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/connor/Projects/Sudo show/Sudo.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Sudo show_Sudo$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Sudo show_Sudo$(DependSuffix): ../Sudo.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/Sudo show_Sudo$(ObjectSuffix) -MF$(IntermediateDirectory)/Sudo show_Sudo$(DependSuffix) -MM "/home/connor/Projects/Sudo show/Sudo.cpp"

$(IntermediateDirectory)/Sudo show_Sudo$(PreprocessSuffix): ../Sudo.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Sudo show_Sudo$(PreprocessSuffix) "/home/connor/Projects/Sudo show/Sudo.cpp"

$(IntermediateDirectory)/Sudo show_bit_matrix$(ObjectSuffix): ../bit_matrix.cpp $(IntermediateDirectory)/Sudo show_bit_matrix$(DependSuffix)
	$(CompilerName) $(SourceSwitch) "/home/connor/Projects/Sudo show/bit_matrix.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/Sudo show_bit_matrix$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Sudo show_bit_matrix$(DependSuffix): ../bit_matrix.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/Sudo show_bit_matrix$(ObjectSuffix) -MF$(IntermediateDirectory)/Sudo show_bit_matrix$(DependSuffix) -MM "/home/connor/Projects/Sudo show/bit_matrix.cpp"

$(IntermediateDirectory)/Sudo show_bit_matrix$(PreprocessSuffix): ../bit_matrix.cpp
	@$(CompilerName) $(CmpOptions) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Sudo show_bit_matrix$(PreprocessSuffix) "/home/connor/Projects/Sudo show/bit_matrix.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/Sudo show_Sudo$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Sudo show_Sudo$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Sudo show_Sudo$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Sudo show_bit_matrix$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Sudo show_bit_matrix$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Sudo show_bit_matrix$(PreprocessSuffix)
	$(RM) $(OutputFile)


