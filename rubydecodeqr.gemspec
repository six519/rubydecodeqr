Gem::Specification.new do |s|
    s.name = "rubydecodeqr"
    s.version = "1.0.0"
    s.date = "2016-01-09"
    s.authors = ["Ferdinand E. Silva"]
    s.email = "ferdinandsilva@ferdinandsilva.com"
    s.summary = "Ruby QR Code Decoder"
    s.homepage = "http://ferdinandsilva.com"
    s.description = "Ruby QR Code Decoder"
    s.files = ["ext/rubydecodeqr/rubydecodeqr.c", "ext/rubydecodeqr/extconf.rb"]
    s.extensions = %w[ext/rubydecodeqr/extconf.rb]
end