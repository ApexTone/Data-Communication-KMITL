
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name CRC_sim -dir "C:/Users/Predator/Desktop/Learning Resources/DataCom/Lab/Lab5/CRC_sim/planAhead_run_3" -part xc6slx9tqg144-3
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "CRC.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {CRC.vhf}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set_property top CRC $srcset
add_files [list {CRC.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc6slx9tqg144-3
