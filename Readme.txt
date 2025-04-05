https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/windows-setup.html#get-started-windows-first-steps

Espressif - Concepts
https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/build-system.html#concepts

API - Guide Lines
	https://docs.espressif.com/projects/esp-idf/en/latest/esp32/
	Kernel Config :- https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/kconfig.html
	
	
	
1. IDF Commands 
    1. Create a new project IDF 
	
		idf.py create-project . IdfWorkspaceSetup
		
			in VS Code we need to create a workspace file to configure idf terminal
			{
				"folders": [
					{
						"path": "."
					}
				],
				"settings": {
					"terminal.integrated.profiles.windows": {
						"PowerShell": {
							"source": "PowerShell",
							"icon": "terminal-powershell"
						},
						"Command Prompt": {
							"path": [
								"${env:windir}\\Sysnative\\cmd.exe",
								"${env:windir}\\System32\\cmd.exe"
							],
							"args": [
								"/k",
								"D:/ProgramFiles/Espressif/idf_cmd_init.bat",
								"esp-idf-27c37c86019777fdf0efdce7b6113735"
							],
							"icon": "terminal-cmd"
						},
						"Git Bash": {
							"source": "Git Bash"
						}
					},
					"terminal.integrated.defaultProfile.windows": "Command Prompt",
					"files.associations": {
						"ledc.h": "c",
						"gpio.h": "c",
						"esp_wifi.h": "c",
						"reg_neo_pix.h": "c",
						"stdio.h": "c"
					}
				}
			}

	1. Build IDF projects
		idf.py build
		
	2. Deploy to esp32/
		idf.py flash -p <COM-PORT>
		
	3. Monitor the output of IDF
		idf.py monitor -p <COM-PORT>
		
	4. To create a project in IDF
		idf.py create-project -p . <project name>
		
	5. To open IDF menu config
		start idf.py menuconfig
		
	6. To clean the build folder
		idf.py fullclean 