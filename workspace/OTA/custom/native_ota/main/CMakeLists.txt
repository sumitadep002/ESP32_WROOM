idf_component_register(SRCS "native_ota.c"
                    INCLUDE_DIRS "."
		    EMBED_TXTFILES ${project_dir}/server_certs/ca_cert.pem)
