// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "WalletCore",
    platforms: [.iOS(.v13)],
    products: [
        .library(name: "WalletCore", targets: ["WalletCore"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "WalletCore",
            url: "https://github.com/trustwallet/wallet-core/releases/download/4.0.21/WalletCore.xcframework.zip",
            checksum: "4597b3f81bcf09056fb119947b2a1a72b6b007caeddc7439be8e6f08c63015e4"
        )
    ]
)
