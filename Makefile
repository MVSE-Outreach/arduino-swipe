
all: build

serve: build
	jekyll serve

serve-drafts: build
	jekyll serve --drafts

build:
	jekyll build

clean:
	rm -rf ./_site/
