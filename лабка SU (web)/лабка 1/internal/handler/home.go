package handlers

import (
	"net/http"
	"web_site/internal/render"
)

func (h *Handler) home(w http.ResponseWriter, r *http.Request) {
	if r.URL.Path != "/" {
		http.Error(w, "Not found", http.StatusNotFound)
		return
	}
	if r.Method != "GET" {
		http.Error(w, "method not GET", http.StatusInternalServerError)
		return
	}
	h.templates.Render(w, r, "home.page.html", &render.PageData{
		Topic: "NATION",
	})
}
