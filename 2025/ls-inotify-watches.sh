#!/usr/bin/env bash

# 1. 当前系统一共用了多少个 inotify watch
echo "Total inotify entries:"
find /proc/*/fdinfo -maxdepth 1 -type f -print0 2>/dev/null \
  | xargs -0 awk '/inotify/ {c++} END {print c}' 2>/dev/null

# 2. 每个进程用了多少（Top 10）
echo
echo "Top 10 processes by inotify watches:"
for pid in /proc/[0-9]*; do
  [ -d "$pid/fdinfo" ] || continue
  count=$(find "$pid/fdinfo" -maxdepth 1 -type f -print0 2>/dev/null \
    | xargs -0 awk '/inotify/ {c++} END {print c+0}' 2>/dev/null)
  [ -z "$count" ] && count=0
  if [ "$count" -gt 0 ]; then
    name=$(ps -p "${pid##*/}" -o comm= 2>/dev/null || echo "?")
    echo "${pid##*/} $count $name"
  fi
done | sort -k2 -nr | head