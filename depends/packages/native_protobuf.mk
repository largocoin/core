package=native_protobuf
$(package)_version=3.8.0
$(package)_download_path=https://github.com/google/protobuf/releases/download/v$($(package)_version)
$(package)_file_name=protobuf-cpp-$($(package)_version).tar.gz
$(package)_sha256_hash=ddc96d83f3b7417da53bce2510b94ad2796465ef8763f7a4e82089157efe97aa

define $(package)_set_vars
$(package)_config_opts=--disable-shared
endef

define $(package)_config_cmds
  $($(package)_autoconf)
endef

define $(package)_build_cmds
  $(MAKE) -C src protoc
endef

define $(package)_stage_cmds
  $(MAKE) -C src DESTDIR=$($(package)_staging_dir) install-strip
endef

define $(package)_postprocess_cmds
  rm -rf lib include
endef
