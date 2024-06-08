b:
	clang -O3 -Wno-deprecated-declarations -o macos_kfd macos_kfd.c

r:
	sync
	./macos_kfd

br:
	make b
	make r

s:
	sudo sysctl kern.maxfiles=262144
	sudo sysctl kern.maxfilesperproc=262144

ipa: 
	xcodebuild clean build CODE_SIGNING_ALLOWED=NO ONLY_ACTIVE_ARCH=NO PRODUCT_BUNDLE_IDENTIFIER="com.xfxxx.kfd" -sdk iphoneos16.3 -scheme kfd -configuration Debug -derivedDataPath build
	ln -sf build/Build/Products/Debug-iphoneos Payload
	rm -rf Payload/kfd.app/Frameworks
	zip -r9 kfd.ipa Payload/kfd.app
