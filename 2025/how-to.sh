# howto function - copilot command generator
howto() {
    if [ -z "$1" ]; then
        echo "Usage: cs <prompt>"
        return 1
    fi
   
    local prompt="$*"
    local cmd=$(copilot --prompt "帮我生成命令但不执行。我将会把你的输出当做命令执行，所以只需要输出命令，不需要输出其它任何内容，不需要包裹在反引号里！！！
：${prompt}" --no-custom-instructions --model claude-haiku-4.5)
   
    if [ -z "$cmd" ]; then
        echo "Failed to generate command"
        return 1
    fi
   
    echo -e "\n\nGenerated command: \033[32m$cmd\033[0m"
    echo -n "Execute? [Y/n] "
    read -r reply
    if [[ -z "$reply" || $reply =~ ^[Yy]$ ]]; then
        eval "$cmd"
    else
        echo "Cancelled"
    fi
}
