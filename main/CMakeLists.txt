#这里选择你需要编译的项目
if(CONFIG_EXAMPLE_BUILD_IIC_SCAN)
    set(project_path "examples/iic_scan/")
elseif(CONFIG_EXAMPLE_BUILD_TOUCH)
    set(project_path "examples/touch/")
elseif(CONFIG_EXAMPLE_BUILD_SCREEN_TOUCH_LVGL_9)
    set(project_path "examples/screen_touch_lvgl_9/")
endif()
        
idf_component_register(SRC_DIRS ${project_path} 
                        INCLUDE_DIRS ${project_path})

target_compile_options(
    ${COMPONENT_LIB}
    PRIVATE -Wno-error=unused-const-variable -Wno-error=delete-non-virtual-dtor
            -Wno-error=implicit-function-declaration -fpermissive)