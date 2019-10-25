#
AudioPlayer#  Be sure to run `pod spec lint XDBLESDK.podspec' to ensure this is a
#  valid sp/ec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  # ―――  Spec Metadata  ―――――――――――――――――――――――――――――――――――――――――――――――――――――――――― #
  #
  #  These will help people to find your library, and whilst it
  #  can feel like a chore to fill in it's definitely to your advantage. The
  #  summary should be tweet-length, and the description more in depth.
  #

s.name         = "AudioPlayer"
s.version      = '1.0.0'
s.license      = { :type => 'MIT', :file => 'LICENSE' }
s.homepage     = 'https://github.com/WangMing1998/audioPlayerSDK.git'
s.author       = { 'WangMing' => '286241793@qq.com' }
s.summary      = 'AdvertiserSDK'
#s.framework    = 'UIKit','Foundation','MediaPlayer','AVFoundation'

s.platform     =  :ios, '8.0'
s.source       =  { :git => 'https://github.com/WangMing1998/audioPlayerSDK.git', :tag => s.version}
#s.source_files = 'AudioplayerSDK/AudioPlayer.framework'

s.vendored_frameworks = 'AudioPlayer.framework'
s.requires_arc = true
s.frameworks   = 'UIKit','CoreBluetooth','Foundation'
#如果静态库引入外部文件，需要添加以下命令，本框架含C++文件，所以要包含C++
s.libraries = "c++", "xml2"
end
