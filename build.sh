#!/bin/bash
if [ $# -ne 1 ]; then
  echo "Usage: $0 <RECIPE.yaml>"
  exit 1
fi

docker run --rm --interactive --tty --device /dev/kvm --group-add $(getent group kvm | cut -d: -f3) --user $(id -u) --workdir /recipes --mount "type=bind,source=$(pwd),destination=/recipes" --security-opt label=disable godebos/debos $1
