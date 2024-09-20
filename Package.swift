// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "WalletCore",
    platforms: [.iOS(.v13)],
    products: [
        .library(name: "WalletCore", targets: ["WalletCore"])
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "WalletCore",
            url: "https://github.com/trustwallet/wallet-core/releases/download/4.1.7/WalletCore.xcframework.zip",
            checksum: "605380c1eb6b71042b93965f5b626fb55a69f6a7b6e4a43d4e0fbcfebe92d487"
        )
    ]
)
