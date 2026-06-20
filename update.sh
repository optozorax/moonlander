#!/usr/bin/env bash
set -euo pipefail

rsync -aiv --delete \
  --exclude='/.git/' \
  --exclude='/_deps/' \
  ../../ keyboards/zsa/moonlander/keymaps/optozorax
