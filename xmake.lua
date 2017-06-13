set_xmakever("2.1.3")
set_languages("gnu++14")

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
	add_links("factorio-mod-info", "boost_system", "yaml-cpp")
	before_build(function (target)
		if not (os.exists("/usr/include/factorio/mod-info.hpp") or os.exists("/usr/include/factorio/mod-info.hpp")) then
			if io.stderr == nil then
				io.stderr = io.open("/dev/stderr", "a")
			end
			io.stderr:print("Need Factorio-Mod-info");
			io.stderr:print("visit https://github.com/745275633/Factorio-Mod-info")
			os.exit(1);
		end
	end)

target("download")
	set_kind("binary")
	add_files("src/download.cpp") 
	add_links("factorio-mod-info", "boost_system", "yaml-cpp")
	before_build(function (target)
		if not (os.exists("/usr/include/factorio/mod-info.hpp") or os.exists("/usr/include/factorio/mod-info.hpp")) then
			if io.stderr == nil then
				io.stderr = io.open("/dev/stderr", "a")
			end
			io.stderr:print("Need Factorio-Mod-info");
			io.stderr:print("visit https://github.com/745275633/Factorio-Mod-info")
			os.exit(1);
		end
	end)

