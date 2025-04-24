-- premake5.lua
workspace "PhotonEngine"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "PhotonEditor"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "PhotonEngine"
	include "PhotonEngine/build-lib.lua"
group ""

include "PhotonEditor/build-app.lua"