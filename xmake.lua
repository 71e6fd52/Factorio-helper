set_xmakever("2.1.3")
set_languages("gnuxx14")

if is_mode("debug") then
	set_symbols("debug")
	set_optimize("none")
	set_warnings("all", "error")
	add_defines("DEBUG")
	add_undefines("NDEBUG")
end

if is_mode("release") then
	set_symbols("hidden")
	set_optimize("fastest")
	set_strip("all")
	set_warnings("none")
	add_defines("NDEBUG")
	add_undefines("DEBUG")
end

target("create_modlist")
	set_kind("binary")
	add_files("src/create_modlist.cpp") 
	add_links("yaml-cpp")
	before_build(function (target)
		assert(os.exists("/usr/lib/libyaml-cpp.so") or os.exists("/usr/local/lib/libyaml-cpp.so"),
			"Need yaml-cpp\nInstall with your package manager\nOr visit https://github.com/jbeder/yaml-cpp")
	end)

target("download-info")
	set_kind("binary")
	add_files("src/download-info.cpp") 
	add_links("factorio-mod-info", "boost_system", "yaml-cpp")
	before_build(function (target)
		assert(os.exists("/usr/include/factorio/mod-info.hpp") or os.exists("/usr/include/factorio/mod-info.hpp"),
			"Need Factorio-Mod-info\nVisit https://github.com/745275633/Factorio-Mod-info")
	end)

target("mod_exist")
	set_kind("binary")
	add_files("src/exist.cpp") 
	add_links("factorio-mod-info", "boost_system")
	before_build(function (target)
		assert(os.exists("/usr/include/factorio/mod-info.hpp") or os.exists("/usr/include/factorio/mod-info.hpp"),
			"Need Factorio-Mod-info\nVisit https://github.com/745275633/Factorio-Mod-info")
	end)

target("search")
	set_kind("binary")
	add_files("src/search.cpp") 
	add_links("factorio-mod-info", "boost_system")
	before_build(function (target)
		assert(os.exists("/usr/include/factorio/mod-info.hpp") or os.exists("/usr/include/factorio/mod-info.hpp"),
			"Need Factorio-Mod-info\nVisit https://github.com/745275633/Factorio-Mod-info")
	end)
