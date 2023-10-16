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
            url: "https://github.com/trustwallet/wallet-core/releases/download/3.3.2/WalletCore.xcframework.zip",
            checksum: "d87c5ae8a313b5a72e7a8ca8d7f7fa84690f895d6389ea81d5a6688ff3cdfd51"
        )
    ]
)
